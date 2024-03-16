#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable: 4996)
#include "hw.h"

/*Input: Reading a matrix from a file
1st line - n
second - m
further rows are like rows of matrix A

Output:
The number is the minimum fine*/

int main() {
	//opening a text file to read
	FILE* file = fopen("matrix.txt", "r");
	CheckFopen(file);
	//readiing a matrix
	int row, col;
	int** matrix;
	CheckFscanf(fscanf(file, "%d\n%d", &row, &col));
	matrix = ReadMatrix(file, row, col);
	Fclose(file);

	int min = FindMinFine(matrix, row, col);
	printf("Minimum fine: %d\nIf the result is zero, check the input data\n", min);
	FreeMatrix(matrix, row);
	return 0;
}
