#ifndef LAB_H
#define LAB_H
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable: 4996)
/*
int FindMinFine(int** matrix, int row, int col);
int FindMinInLine(int* arr, int size);
void CheckFopen(FILE* file);
void Fclose(FILE* file);
void CheckMalloc(int* arr);
void CheckMalloc2D(int** arr);
void CheckFscanf(int value);
int** AllocMatrix(int row, int col);
int** ReadMatrix(FILE* file, int n, int m);
void FreeMatrix(int** matrix, int row);
int FindMinFine(int** matrix, int row, int col);
*/

void FreeMatrix(int** matrix, int row) {
	for (int i = 0; i < row; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

int FindMinInLine(int* arr, int size) {
	if (arr == NULL) return 0;
	int min = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

void CheckFopen(FILE* file) {
	if (!file) {
		printf("Error opening file\n");
		exit(1);
	}
}

void Fclose(FILE* file) {
	if(fclose(file) == EOF) {
		printf("Error closing file\n");
		exit(1);
	}
}

void CheckMalloc(int* arr) {
	if (!arr) {
		printf("Error allocating memory\n");
		exit(1);
	}
}

void CheckMalloc2D(int** arr) {
	if (!arr) {
		printf("Error allocating memory\n");
		exit(1);
	}
}

//выделение памяти для матрицы
int** AllocMatrix(int row, int col) {
	int** matrix = (int**)malloc(row * sizeof(int*));
	CheckMalloc2D(matrix);
	for (int i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(col * sizeof(int));
		CheckMalloc(matrix[i]);
	}
	return matrix;
}

void CheckFscanf(int value) {
	if (value == EOF) {
		printf("Error reading file\n Check input file\n");
		exit(1);
	}
}

int** ReadMatrix(FILE* file, int row, int col) {
	int** matrix = AllocMatrix(row, col);
	//чтение матрицы
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			CheckFscanf(fscanf(file, "%d", &matrix[i][j]));
		}
	}
	return matrix;
}

//поиск минимально возможного штрафа
int FindMinFine(int** matrix, int row, int col) {
	//проверка на неподходящие входные данные
	if ((row <= 0) || (col <= 0) || matrix == NULL) return 0;
	//вспомогательная матрица для записи минимального штрафа в каждой ячейке
	int** fine = AllocMatrix(row, col);

	//первая строка этой таблицы соответствует первой строке исходной матрицы
	for (int j = 0; j < col; j++) {
		fine[0][j] = matrix[0][j];
	}

	//рассматриваются все возможные пути (два или три) в данную клетку, записывается минимально из этих значений
	for (int i = 1; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fine[i][j] = fine[i - 1][j] + matrix[i][j];
			//тк для крайних столбцов есть только два пути, а не три, добавляются условия на j
			if (j > 0) {
				if (fine[i][j] > fine[i - 1][j - 1] + matrix[i][j]) {
					fine[i][j] = fine[i - 1][j - 1] + matrix[i][j];
				}
			}
			if (j < col - 1) {
				if (fine[i][j] > fine[i - 1][j + 1] + matrix[i][j]) {
					fine[i][j] = fine[i - 1][j + 1] + matrix[i][j];
				}
			}
		}
	}
	//находим минимальное значение в последней строке получившейся матрицы
	int min = FindMinInLine(fine[row - 1], col);
	FreeMatrix(fine, row);
	return min;
}

#endif