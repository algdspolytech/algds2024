#include <stdio.h>
#include <stdlib.h>
#include "maxCost.h"

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        printf("Ошибка ввода\n");
        return 1;
    }

    int **cost = (int **) malloc(N * sizeof(int *));
    if (cost == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        cost[i] = (int *) malloc(N * sizeof(int));
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
