#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 7

#define M 13
//#define ERROR_OPEN_FILE -1

#define CREATE_ERROR -2

typedef int u32;

u32* create_a(u32 num)
{ 
    if (num == 0 || num == 1) {
         printf("there must be 2 numbers at least");
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
    u32 max = -1, index_max = 0;
    u32* c = (u32*)malloc(sizeof(u32) * (n));
    u32* b = (u32*)malloc(sizeof(u32) * (n));
    for (int i = 0; i < n; i++) {
        b[i] = 0;
    }
    c[0] = -1;
    c[1] = 0;
    for (int i = 1; i <= n; i++) {
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
   
    printf("%d\n", a[index_max]);
    while (index_max != 0) {

        index_max = c[index_max];
        printf("%d\n", a[index_max]);

    }
   
}

void tests()
{
    printf("1. Тест 'в массиве 1 элемент' \n");
    u32 m = 1;
    u32* a = malloc(m * sizeof(u32));
    a[0] = 1;
    proccessing(a, m);
    free(a);
    printf("\n");

    printf("2. Обратный порядок элементов\n");
    m = 5;
    a = malloc(m * sizeof(u32));
    printf("массив = ");
    for (u32 i = 0; i < m; i++)
    {
        a[i] = 5 - i;
        printf("%d ", a[i]);
    }

    proccessing(a, m);
    free(a);
    printf("\n");

    printf("3. Тест на две подпоследовательности разной длины\n");
    //M = 13;
    u32 b[M] = { 1,2,2,2,4,5,6,3,4,7,8,9,6 };
    printf("Массив = {1,2,2,2,4,5,6,3,4,7,8,9,6}\n");
    proccessing(b,m);
    printf("\n");

}

u32 main() 
{
    setlocale(LC_CTYPE, "Rus");
    int n = 5;
    printf("\n\n\n");
    tests();
    printf("\n\n\n");
    puts("enter ur numbres");
    u32* a = create_a(n);

    printf("\n\n\n");
    puts("ur answer:\n");
    proccessing(a, n);
    
    free(a);
    return 0;
}