#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Method.h"

int main() {
    int n, k;
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);
    printf("%d ", Amount(n, k));
    return 0;
}