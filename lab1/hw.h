#ifndef LAB_H
#define LAB_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable: 4996)

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

//memory allocation for matrix
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
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			CheckFscanf(fscanf(file, "%d", &matrix[i][j]));
		}
	}
	return matrix;
}

//search for the minimum possible fine
int FindMinFine(int** matrix, int row, int col) {
	//check for invalid input data
	if ((row <= 0) || (col <= 0) || matrix == NULL) return 0;
	//help matrix to record the minimum penalty in each cell
	int** fine = AllocMatrix(row, col);

	//the first row of this table corresponds to the first row of the original matrix
	for (int j = 0; j < col; j++) {
		fine[0][j] = matrix[0][j];
	}

	//all possible paths (two or three) to a given cell are considered, the minimum of these values is written down
	for (int i = 1; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fine[i][j] = fine[i - 1][j] + matrix[i][j];
			//since for the outer columns there are only two paths, not three, conditions are added on j
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
	//finding the minimum value in the last row of the resulting matrix
	int min = FindMinInLine(fine[row - 1], col);
	FreeMatrix(fine, row);
	return min;
}

#endif
