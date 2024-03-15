#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MEMORY_ERROR 2 

double** createArray(int n, int m) {
    double** array = (double**)malloc(n * sizeof(double*));
    if (array == NULL) {
        return MEMORY_ERROR;
    }
    for (int i = 0; i < n; i++) {
        array[i] = (double*)malloc(m * sizeof(double));
    }
    return array;
}

void freeArray(double** array, int n) {
    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
}

double minimum(double a, double b) {
    if (a <= b)
        return a;
    else 
        return b;

}

int minCost(char X[], char Y[], double d, double i, double c) {
    int m = strlen(X);
    int n = strlen(Y);
    double** ways = createArray(m + 1, n + 1);

    for (int i = 0; i <= m; i++) {
        ways[i][0] = i * d;
    }
    for (int j = 0; j <= n; j++) {
        ways[0][j] = j * i;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] != Y[j - 1]) {
                ways[i][j] = minimum(ways[i - 1][j - 1] + c, min(ways[i - 1][j] + d, ways[i][j - 1] + i));
            }
            else {
                ways[i][j] = ways[i - 1][j - 1];
            }
        }
    }
    double result = ways[m][n];
    freeArray(ways, m + 1);

    return result;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int d, i, c;
    char X[1000], Y[1000];

    printf("Введите значения d, i, c: ");
    scanf("%d %d %d", &d, &i, &c);

    printf("Введите строку X: ");
    scanf("%s", X);

    printf("Введите строку Y: ");
    scanf("%s", Y);

    int result = minCost(X, Y, d, i, c);
    printf("Минимальная стоимость преобразования: %d\n", result);

    return 0;
}
