#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int Solution(int* Coord[2], int n) {
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
	for (int i = 0; i < n; i++)
	{
		free(Coord[i]);
	}
	free(Coord);
	free(Diagonals);
	return (1);
}

int main() {

	return;
}