#include <stdio.h>
#include "matrix_operations.h"

#define INF 2147483647 // Бесконечность 

int min(int a, int b) {
    return a < b ? a : b; // Функция для нахождения минимума
}

void readMatrixSize(int *n, int *m) {
    // Функция для считывания размеров матрицы с клавиатуры
    printf("Введите количество строк и столбцов матрицы через пробел: ");
    scanf("%d %d", n, m);
}

void readMatrix(int n, int m, int A[n][m]) {
    // Функция для считывания элементов матрицы
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}

void initializePenalty(int n, int m, int penalty[n][m]) {
    // Инициализируем penalty с INF
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            penalty[i][j] = INF;
        }
    }
}

void fillPenalty(int n, int m, int A[n][m], int penalty[n][m]) {
    // Начальная строка
    for (int j = 0; j < m; j++) {
        penalty[0][j] = A[0][j];
    }

    // Заполняем penalty по строкам
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = -1; k <= 1; k++) {
                if (j + k >= 0 && j + k < m) {
                    penalty[i][j] = min(penalty[i][j], penalty[i - 1][j + k] + A[i][j]);
                }
            }
        }
    }
}

void printPenalty(int n, int m, int penalty[n][m]) {
    // Выводим минимальный штраф на каждой строке
    for (int j = 0; j < m; j++) {
        printf("Минимальный штраф для прохода из первой строки в последнюю в столбце %d: %d\n", j + 1, penalty[n - 1][j]);
    }
}

