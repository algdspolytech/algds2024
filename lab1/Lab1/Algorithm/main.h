//#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <float.h>

#define NUMBER_OF_POINTS_ERROR 1
#define MEMORY_ERROR 2

#define minimal(a, b) (((a)<(b))?(a):(b))
#define three_minimal(a, b, c) minimal(minimal(a, b), c)

// Structure of a point in 2D plane
typedef struct {
    double x, y;
} Point;

// Function to find distance between two points in a plane
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y));
}

// A Dynamic programming based function to find minimum cost for convex polygon triangulation.
double** Triangulation(Point points[], int n) {
    // Table to store results of subproblems
    // Table[i][j] stores cost of triangulation of points from i to j
    // The entry table[0][n-1] stores the final result.
    double** table = (double**)malloc(sizeof(double*) * n);
    for (int i = 0; i < n; i++) {
        table[i] = (double*)malloc(sizeof(double) * n);
    }

    // Fill table using above recursive formula.
    // Note that the table is filled in diagonal fashion i.e.,
    // from diagonal elements to table[0][n-1] which is the result.
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            if (fabs(j - i) <= 2)
                table[i][j] = DBL_MAX;
            else {
                table[i][j] = DBL_MAX;
                for (int k = i + 1; k < j - 1; k++) { // i
                    double minDiag = three_minimal(table[i][k], table[k][j], distance(points[k], points[j]));
                    if (table[i][j] > minDiag)
                        table[i][j] = minDiag;
                }

            }
        }
    }
    return table;
}