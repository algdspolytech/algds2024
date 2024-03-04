#ifndef Lab_1_H_
#define Lab_1_H_
#include<stdlib.h>
#define M 4
#define MIN(a,b) (((a)<(b))?(a):(b))
// параметры функции : матрица A и B: длины улицы направа и вверх
double solve(double A[M][M-1], double B[M-1][M]) {
	double** P = (double**)malloc(M * sizeof(double*));
	for (int i = 0; i < M; i++) {
		P[i] = (double*)malloc(sizeof(double) * M);
	}
	P[0][M - 1] = 0;
	for (int i = M - 2; i >= 0; i--) {
		P[0][i] = P[0][i + 1] + A[0][i];
	}
	for (int i = 1; i < M; i++) {
		P[i][M - 1] = P[i - 1][M - 1] + B[i - 1][M - 1];
	}
	for (int i = 1; i < M; i++) {
		for (int j = 2; j >= 0; j--) {
			P[i][j] = MIN(P[i - 1][j] + B[i - 1][j], P[i][j + 1] + A[i][j]);
		}
	}
	double result = P[M - 1][0];

	for (int i = 0; i < M; i++) {
		free(P[i]);
	}
	free(P);
	return result;
}
#endif
