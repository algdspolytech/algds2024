#include <stdio.h>
#include "source/func.h"

int main() {
    int n, k;

    printf("Enter the bit depth of the number:\n");
    scanf_s("%d", &n);
    printf("Enter the required sum:\n");
    scanf_s("%d", &k);

    printf("%d\n", solve(n, k));
    
    return 0;
}
