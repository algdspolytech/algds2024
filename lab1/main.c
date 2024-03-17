#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned n = 0;
    struct Point *array = initPoints(&n);
    if (!array) {
        printf("error, exit\n");
        return 1;
    }
    double *distance = malloc((sizeof(double)) * (n));
    fill_distance_array(n, array, distance);
    unsigned min_index = array_min_index(distance, n);
    printf("Min distance: %f\nMin distance index: %u\n", distance[min_index],
           min_index);
    printf("resulting point index for diagonals: %u", min_index);
    free(distance);
    free(array);
    return 0;
}


