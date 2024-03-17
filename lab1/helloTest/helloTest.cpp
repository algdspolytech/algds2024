// helloTest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "dyn_prog.h"

#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>

#define MAXN 100
#define MAXA 1000

int main()
{
    /*std::cout << "Hello World!\n";

    printf("%d", doubler(3)); */

    //////////////////////////////////
    int n, A;

    printf("Enter the number of items n: ");
    scanf_s("%d", &n);

    printf("Enter the value of A (max weight): ");
    scanf_s("%d", &A);

    int b[MAXN], c[MAXN];
    int F[MAXN + 1][MAXA + 1] = { 0 };

    printf("Enter the weights of items b[1..n]:\n");
    for (int i = 1; i <= n; i++) {
        printf("#%d ", i);
        scanf_s("%d", &b[i]);
        if (b[i] > n) {
            printf("Error: b[i] should be smaller than n = %d\n", n);
            return 1;
        }
    }

    printf("Enter the costs of items c[1..n]:\n");
    for (int i = 1; i <= n; i++) {
        printf("#%d ", i);
        scanf_s("%d", &c[i]);
    }

    int p = 0; //мощность искомого подмножества
   int ans = findSubset(n, A, &p, b, c);
    for (int i = 0; i < p; i++)
        printf("%d, ", ans);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
