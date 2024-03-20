#include "maxCost.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int _max(int a, int b, int c) {
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    return c;
}

int maxCost(int **cost, int N) {
    if (N == 0) {
        printf("Размер доски равен нулю\n");
        return 0;
    }
    int **dp = (int **) malloc(N * sizeof(int *));
    if (dp == NULL) {
        printf("Ошибка выделения памяти\n");
        return -1;
    }

    for (int i = 0; i < N; i++) {
        dp[i] = (int *) malloc(N * sizeof(int));
        if (dp[i] == NULL) {
            printf("Ошибка выделения памяти\n");
            return -1;
        }
    }

    for (int i = 0; i < N; i++)
        dp[0][i] = cost[0][i];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int upLeft = (j > 0) ? dp[i - 1][j - 1] : INT_MIN;
            int upRight = (j < N - 1) ? dp[i - 1][j + 1] : INT_MIN;
            int up = dp[i - 1][j];
            dp[i][j] = cost[i][j] + _max(upLeft, upRight, up);
        }
    }

    int result = INT_MIN;
    for (int i = 0; i < N; i++)
        if (dp[N - 1][i] > result)
            result = dp[N - 1][i];

    for (int i = 0; i < N; i++)
        free(dp[i]);
    free(dp);

    return result;
}
