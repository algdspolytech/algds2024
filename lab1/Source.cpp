#include <stdio.h>
#include <stdlib.h>
#include "Source.h"
#pragma warning(disable 4996)
#define INF 1000000000 // Большое число, заменяющее бесконечность

int Min(int a, int b, int c) {
    int min_val = a;
    if (b < min_val) min_val = b;
    if (c < min_val) min_val = c;
    return min_val;
}

int main() {
    int n, m;
    printf("Введите количество строк и столбцов матрицы (через пробел): ");
    scanf_s("%d %d", &n, &m);

    int** A = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(m * sizeof(int));
    }

    printf("Введите элементы матрицы (по строкам, через пробел):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &A[i][j]);
        }
    }

    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(m * sizeof(int));
    }

    // Инициализируем первую строку dp значениями матрицы A
    for (int j = 0; j < m; j++) {
        dp[0][j] = A[0][j];
    }

    // Заполняем dp поочередно, начиная со второй строки
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int left = (j > 0) ? dp[i - 1][j - 1] : INF;
            int mid = dp[i - 1][j];
            int right = (j < m - 1) ? dp[i - 1][j + 1] : INF;
            dp[i][j] = A[i][j] + Min(left, mid, right);
        }
    }

    // Находим минимальный штраф на последней строке
    int min_penalty = INF;
    for (int j = 0; j < m; j++) {
        if (dp[n - 1][j] < min_penalty) {
            min_penalty = dp[n - 1][j];
        }
    }

    printf("Минимальный штраф: %d\n", min_penalty);

    // Освобождаем выделенную память
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(dp[i]);
    }
    free(A);
    free(dp);

    return 0;
}