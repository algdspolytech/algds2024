//
// Created by nick on 10.03.2024.
//

#ifndef LAB1_MAIN_H
#define LAB1_MAIN_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

double get_distance(struct Point a, struct Point b) {
    return sqrt((pow((a.x - b.x), 2) + pow((a.y - b.y), 2)));
}

unsigned array_min_index(double *v, unsigned size) {
    double min = 10000;
    unsigned min_index = 0;
    for (unsigned index = 0; index < size; index++) {
        if (v[index] < min) {
            min = v[index];
            min_index = index;
        }
    }
    return min_index;
}

double get_max(double *array, unsigned n) {
    double max = -10000;
    for (unsigned index = 0; index < n; index++) {
        if (array[index] > max) {
            max = array[index];
        }
    }
    return max;
}

struct Point *initPoints(unsigned *n) {
    FILE *f = fopen("../input.txt", "r");
    if (f) {
        fscanf(f, "%u", n);
        if (*n == 3) {
            printf("can't process polygon with n== %u\n", *n);
            return NULL;
        }
        struct Point *array = malloc((sizeof(struct Point)) * (*n));
        printf("Points n == %i\n", (*n));
        for (unsigned i = 0; i < (*n); i++) {
            fscanf(f, "%i %i", &array[i].x, &array[i].y);
            printf("\tPoint %i: (%i, %i)\n", i, array[i].x, array[i].y);
        }
        fclose(f);
        return array;
    } else {
        printf("cannot open file input.txt\n");
    }
    return NULL;
}

#endif // LAB1_MAIN_H
