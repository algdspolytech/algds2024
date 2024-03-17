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
    double min = INT_MAX;
    unsigned min_index = UINT_MAX;
    for (unsigned index = 0; index < size; index++) {
        if (v[index] < min) {
            min = v[index];
            min_index = index;
        }
    }
    return min_index;
}

double get_max(double *array, unsigned n) {
    double max = INT_MIN;
    for (unsigned index = 0; index < n; index++) {
        if (array[index] > max) {
            max = array[index];
        }
    }
    return max;
}

void fill_distance_array(unsigned int n, const struct Point *array, double *distance) {
    double *local_distance = malloc((sizeof(double)) * (n - 3));

    unsigned local_index = 0;
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            if ((i == j) || ((j + 1) % n == i) || ((j - 1) % n == i) ||
                ((i + 1) % n == j) || ((i - 1) % n == j))
                continue;
            local_distance[local_index] = get_distance(array[i], array[j]);
            local_index++;
        }
        distance[i] = get_max(local_distance, n - 3);
        local_index = 0;
    }
    free(local_distance);
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
