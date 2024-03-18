#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int max(int a, int b, int c) {
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    return c;
}

int maxCost(int** cost, int N) {
    int** dp = (int**)malloc(N * sizeof(int*));
    if (dp == NULL) {
        printf("Ошибка выделения памяти\n");
        return -1;
    }

    for (int i = 0; i < N; i++) {
        dp[i] = (int*)malloc(N * sizeof(int));
        if (dp[i] == NULL) {
            printf("Ошибка выделения памяти\n");
            return -1;
        }
    }

    for (int i = 0; i < N; i++)
        dp[0][i] = cost[0][i];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int upLeft = (j > 0) ? dp[i - 1][j - 1] : 0;
            int upRight = (j < N - 1) ? dp[i - 1][j + 1] : 0;
            int up = dp[i - 1][j];
            dp[i][j] = cost[i][j] + max(upLeft, upRight, up);
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++)
        if (dp[N - 1][i] > result)
            result = dp[N - 1][i];

    for (int i = 0; i < N; i++)
        free(dp[i]);
    free(dp);

    return result;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        printf("Ошибка ввода\n");
        return 1;
    }

    int** cost = (int**)malloc(N * sizeof(int*));
    if (cost == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        cost[i] = (int*)malloc(N * sizeof(int));
        if (cost[i] == NULL) {
            printf("Ошибка выделения памяти\n");
            return 1;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (scanf("%d", &cost[i][j]) != 1) {
                printf("Ошибка ввода\n");
                return 1;
            }

    printf("%d\n", maxCost(cost, N));

    for (int i = 0; i < N; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
