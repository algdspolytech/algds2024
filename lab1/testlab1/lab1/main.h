#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MEMORY_ERROR 2 

double** createArray(int n, int m) {
    double** array = (double**)malloc(n * sizeof(double*));
    if (array == NULL) {
        printf("error of memory");
    }
    for (int i = 0; i < n; i++) {
        array[i] = (double*)malloc(m * sizeof(double));
    }
    return array;
}

void freeArray(double** array, int n) {
    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
}

double minimum(double a, double b) {
    if (a <= b)
        return a;
    else
        return b;
}

double minCost(char X[], char Y[], double d, double i, double c) {
    int m = strlen(X);
    int n = strlen(Y);
    double** ways = createArray(m + 1, n + 1);

    for (int i = 0; i <= m; i++) {
        ways[i][0] = i * d;
    }
    for (int j = 0; j <= n; j++) {
        ways[0][j] = j * i;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] != Y[j - 1]) {
                ways[i][j] = minimum(ways[i - 1][j - 1] + c, minimum(ways[i - 1][j] + d, ways[i][j - 1] + i));
            }
            else {
                ways[i][j] = ways[i - 1][j - 1];
            }
        }
    }
    double result = ways[m][n];
    freeArray(ways, m + 1);

    return result;
}
