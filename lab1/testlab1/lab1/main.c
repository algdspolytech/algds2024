#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include "main.h"


int main() {
    setlocale(LC_ALL, "Rus");
    int d, i, c;
    char X[1000], Y[1000];

    printf("������� �������� d, i, c: ");
    scanf("%d %d %d", &d, &i, &c);

    printf("������� ������ X: ");
    scanf("%s", X);

    printf("������� ������ Y: ");
    scanf("%s", Y);

    int result = minCost(X, Y, d, i, c);
    printf("����������� ��������� ��������������: %d\n", result);

    return 0;
}
