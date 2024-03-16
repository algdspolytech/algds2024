#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include "main.h"


int main() {
    setlocale(LC_ALL, "Rus");
    int d, i, c;
    char X[1000], Y[1000];

    printf("Введите значения d, i, c: ");
    scanf("%d %d %d", &d, &i, &c);

    printf("Введите строку X: ");
    scanf("%s", X);

    printf("Введите строку Y: ");
    scanf("%s", Y);

    int result = minCost(X, Y, d, i, c);
    printf("Минимальная стоимость преобразования: %d\n", result);

    return 0;
}
