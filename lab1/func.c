#include "func.h"
#include <stdlib.h>

int count_numbers(int n, int k) {
    int **tmp = (int**) calloc(sizeof(int*), (n + 1));
    for (int i = 0; i <= n; i++) {
        tmp[i] = (int*) calloc(sizeof(int),(k + 1));
    }

    for (int i = 0; i <= 9 && i <= k; i++) {
        tmp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int d = 0; d <= 9 && d <= j; d++) {
                tmp[i][j] += tmp[i - 1][j - d];
            }
        }
    }

    int result = tmp[n][k];

    for (int i = 0; i <= n; i++) {
        free(tmp[i]);
    }
    free(tmp);

    return result;
}