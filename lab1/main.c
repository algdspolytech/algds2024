#include <stdio.h>
#include "main.h"

int main() {
    int n, k;
    printf("Enter the number of digits n: ");
    scanf("%d", &n);
    printf("Enter the sum of digits k: ");
    scanf("%d", &k);
    unsigned long long int count = Count_number(n, k);
    printf("%d ", count);
    return 0;
}