#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#define INF 2147483647

// Функции
int min(int a, int b);
void readMatrixSize(int *n, int *m);
void readMatrix(int n, int m, int A[n][m]);
void initializePenalty(int n, int m, int penalty[n][m]);
void fillPenalty(int n, int m, int A[n][m], int penalty[n][m]);
void printPenalty(int n, int m, int penalty[n][m]);

#endif /* MATRIX_OPERATIONS_H */

