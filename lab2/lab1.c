#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

char* findLCS(char *X, char *Y, int m, int n) {
    int L[m+1][n+1];
    int i, j;

    // Заполнение таблицы L для нахождения длины НОП
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }

    // Восстановление НОП
    int index = L[m][n];
    char* lcs = (char*)malloc((index + 1) * sizeof(char));
    lcs[index] = '\0'; // Установка терминирующего нулевого символа

    i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1]; // Добавляем символ к НОП
            i--; j--; index--;     // Перемещаемся по диагонали назад
        } else if (L[i-1][j] > L[i][j-1]) {
            i--; // Перемещение вверх, если элемент слева меньше
        } else {
            j--; // Иначе перемещаемся влево
        }
    }
    
    return lcs;
}
