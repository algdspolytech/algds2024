#include "func.h"


matrix initMatrix(int n, int k) {
    if (n == 0 || k == 0)
        return NULL;
        
    matrix result = malloc(sizeof(int*) * (n + 1));

    if (result != NULL) {
        for (int index = 0; index < n + 1; index++) {
            int* value = malloc(sizeof(int) * (k + 1));

            if (value == NULL)
                return NULL;
            
            value[0] = 1;
            result[index] = value;
        }

        for (int index = 0; index < k + 1; index++) {
            result[0][index] = 0;
        }
    }

    return result;
}

void destrMatrix(int n, int k, matrix matr) {
    if (matr == NULL)
        return;

    for (int index = 0; index < n + 1; index++) {
        free(matr[index]);
    }
}

int solve(int n, int k) {
    matrix matr = initMatrix(n, k);

    if (matr == NULL)
        return -1;

    for (int row = 1; row < n + 1; row++) {
        for (int col = 1; col < k + 1; col++) {
            matr[row][col] = matr[row - 1][col] + matr[row][col - 1];
        }
    }

    int result = matr[n][k];

    destrMatrix(n, k, matr);
    free(matr);

    return result;
}
