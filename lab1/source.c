#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define N 7

//#define ERROR_OPEN_FILE -1

#define CREATE_ERROR -2

typedef int u32;

u32* create_a(u32 num)
{ 
    if (num == 0) {
        printf("there must be 2 numbers at least");
        exit(1);
    }
    if (num == 1) {
        printf("there are must be more then 1 number");
        exit(1);
    }
    u32* a = malloc(num * sizeof(u32));
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == " " || a[i] == '\0') {
            exit(CREATE_ERROR);
        }
    }
    return a;
}


void proccessing(u32* a, int n) 
{
    u32 max = 1, index_max = 1;
    u32* c = (u32*)malloc(sizeof(u32) * (n + 1));
    u32* b = (u32*)malloc(sizeof(u32) * (n + 1));
    for (int i = 2; i < n+1; i++) {
        b[i] = 0;
    }
    b[1] = 1;
    c[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
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
   
    while (index_max != 0){
        printf("%d\n", a[index_max]);
        index_max = c[index_max];
    }
}

void test_proccwssing(int n) 
{
    u32* a = create_a(n);
    proccessing(a, n);


}

u32 main() 
{
    u32* a = create_a(N);
    printf("\n\n\n");
    proccessing(a, N);
    free(a);
    return 0;
}