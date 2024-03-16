#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable: 4996)
#include "hw.h"

/*Входные данные: Чтение матрицы из файла
1ая строка - n
вторая - m
далее строки - как строки матрицы А

Выходные данные:
Число - минимальный штраф*/

int main() {
	system("chcp 1251");
	setlocale(LC_CTYPE, "Russian");
	//открытие файла для чтения
	FILE* file = fopen("matrix.txt", "r");
	CheckFopen(file);
	//чтение матрицы
	int row, col;
	int** matrix;
	CheckFscanf(fscanf(file, "%d\n%d", &row, &col));
	matrix = ReadMatrix(file, row, col);
	Fclose(file);

	int min = FindMinFine(matrix, row, col);
	printf("Размер минимального штрафа : %d\nЕсли результат нулевой, проверьте входные данные\n", min);
	FreeMatrix(matrix, row);
	return 0;
}