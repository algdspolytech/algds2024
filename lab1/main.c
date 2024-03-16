#include <stdio.h>
#include "matrix_operations.h"

int main() {
    int n, m;
    input_matrix_dimensions(&n, &m);

    int** matrix = allocate_matrix(n, m);
    input_matrix_elements(matrix, n, m);

    int minPenalty = min_penalty(matrix, n, m);
    printf("Minimum penalty to traverse the matrix: %d\n", minPenalty);

    free_matrix(matrix, n);
    return 0;
}
