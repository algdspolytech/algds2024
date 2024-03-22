#include "stdlib.h"
#include <stdio.h>
#include "main.h"

int main(void) {
    int N, A;
    printf("Enter num of elements: ");
    scanf("%d", &N);
    printf("Enter max weight: ");
    scanf("%d", &A);
    int *weights = (int *) calloc(N, sizeof(int));
    int *values = (int *) calloc(N, sizeof(int));

    printf("Enter weight elements:\n");
    for (int j = 0; j < N; j++) {
        printf("Weight: ");
        scanf("%d", &weights[j]);
        if (weights[j] > N) {
            printf("Error!");
            exit(1);
        }
    }
    printf("Enter cost elements:\n");
    for (int j = 0; j < N; j++) {
        printf("Cost: ");
        scanf("%d", &values[j]);
    }

    int result = Result(N, A, weights, values);
    printf("Max sum cost elements: %d\n", result);

    return 0;
}
