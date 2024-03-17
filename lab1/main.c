#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

int main() {
    setlocale(LC_ALL, "Rus");
    printf("Melko Timofey 5030102/20003\n");
    int n, k;
    printf("Enter n, k: ");
    do {
        scanf("%d %d", &n, &k);
    } while (n <= 0 || k <= 0);
    int result = count_numbers(n, k);
    printf("Count of numbers: %d\n", result);
    return 0;
}