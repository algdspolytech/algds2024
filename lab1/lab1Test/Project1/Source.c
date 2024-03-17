#include <stdio.h>
#include <stdlib.h>
#include "lab1.h"

#pragma warning(disable:4996)


int main() {
    int n, k;

    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);

    printf("Count of different path: %d\n", countPaths(n, k));

    return 0;
}
