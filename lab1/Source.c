#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int u32;

u32* input(u32* num)
{
    u32 i, n;
    printf("input number : ");
    scanf("%d", &n);
    if (n == 0) {
        exit(1);
    }
    u32* a = malloc(n * sizeof(u32));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    *num = n;
    return a;
}

u32* create_tmp(u32* a, u32 n) {
    int k = 1;
    u32* tmp = (u32*)malloc(sizeof(u32) * n);
    tmp[0] = 1;
    for (u32 i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            k++;
            tmp[i] = k;
        }
        else {
            tmp[i] = 1;
            k = 1;
        }
    }
    return tmp;
}

void proccessing(u32* a, u32* b, int n) {
    u32 max=1, index_max=1;
    u32* c = (u32*)malloc(sizeof(u32)*n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && b[i] < b[j] + 1) {
                c[i] = j;
                b[i] = b[j] + 1;
                if (b[i] > max) {
                    max = b[i];
                    index_max = i;
                }
            }
        }
    }
    
    while (index_max != 0) {
        printf("%d ", a[index_max]);
        index_max = c[index_max];
    }
}

u32 main() {
    u32 n;
    u32* a = input(&n);
   // printf("Printed mass: ");
   // output(a, n);
    printf("\n\n\n");
    u32* b = create_tmp(a, n);
   // output(b, n);
    proccessing(a, b, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n\n");

    free(a);
    free(b);
    return 0;
}