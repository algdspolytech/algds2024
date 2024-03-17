#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned n = 0;
    struct Point *array = initPoints(&n);
    if (!array){
        printf("error, exit\n");
        return 1;
    }
    double *local_distance = malloc((sizeof(double)) * (n - 3));
    double *distance = malloc((sizeof(double)) * (n));

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

    unsigned min_index = array_min_index(distance, n);
    printf("Min distance: %f\nMin distance index: %u\n", distance[min_index],
           min_index);
    free(distance);
    free(local_distance);
    free(array);
    return 0;
}
