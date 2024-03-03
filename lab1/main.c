#include <stdio.h>

#define INF 2147483647 // Бесконечность 

int min(int a, int b) {
    return a < b ? a : b; // Функция для нахождения минимума
}

int main() {
    int n, m;
    printf("Введите количество строк и столбцов матрицы через пробел: ");
    scanf("%d %d", &n, &m);

    int A[n][m];
    int penalty[n][m]; // Массив для хранения минимальных значений штрафов

    // Считываем матрицу A
    printf("Введите элементы матрицы:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Инициализируем penalty с INF
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            penalty[i][j] = INF;
        }
    }

    // Начальная строка
    for(int j = 0; j < m; j++) {
        penalty[0][j] = A[0][j];
    }

    // Заполняем penalty по строкам
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = -1; k <= 1; k++) {
                if(j + k >= 0 && j + k < m) {
                    penalty[i][j] = min(penalty[i][j], penalty[i - 1][j + k] + A[i][j]);
                }
            }
        }
    }

    // Выводим минимальный штраф на каждой стрдке
    for(int j = 0; j < m; j++) {
        printf("Минимальный штраф для прохода из первой строки в последнюю в столбце %d: %d\n", j+1, penalty[n-1][j]);
    }

    return 0;
}
