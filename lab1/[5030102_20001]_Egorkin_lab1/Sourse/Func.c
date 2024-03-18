#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include<stdio.h>
#include "Header.h"


double Diagonal_Value(int x1, int x2, int y1, int y2) {
	double value = sqrt((pow(x1 - x2, 2) + pow(y1 - y2, 2)));
	return(value);
}

double* Find_Diagonal(const int coord[3][2], const int size) {
	double** diagonals;
	double* Ans = (double*)malloc((size - 3) * sizeof(double));
	double Max_diagonal = 0, Min_diagonal = -1;
	diagonals = (double**)malloc((size) * sizeof(double));
	for (int i = 0; i < size; i++) {
		diagonals[i] = (double*)malloc((size - 3) * sizeof(double));
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 3; j++) {
			diagonals[i][j] = Diagonal_Value(coord[i][0], coord[(i + 2 + j) % size][0], coord[i][1], coord[(i + 2 + j) % size][1]);
			if (Max_diagonal < diagonals[i][j])
				Max_diagonal = diagonals[i][j];
		}
		if ((Min_diagonal > Max_diagonal) || (Min_diagonal == -1)) {
			Min_diagonal = Max_diagonal;
			for (int temp = 0; temp < size - 3; temp++) {
				Ans[temp] = diagonals[i][temp];
			}
		}
		Max_diagonal = 0;
	}
	for (int i = 0; i < size; i++)
	{
		free(diagonals[i]);
	}
	free(diagonals);
	return(Ans);
}


int Solution(const int Coord[][2], int n) {
	if (n < 3) {
		printf("Error! Not Enoght Coordinats");
		return(-1);
	}
	if (n == 3) {
		printf("There are 0 diagonals");
		return(0);
	}
	double* Diagonals = (double*)malloc((n - 3) * sizeof(double));
	Diagonals = Find_Diagonal(Coord, n);
	for (int i = 0; i < n - 3; i++) {
		printf("%f ", Diagonals[i]);
	}

	return (1);
}