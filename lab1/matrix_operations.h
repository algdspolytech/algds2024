#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#define INF 2147483647


int min(int a, int b);
void readMatrixSize(int *n, int *m);
void readMatrix(int n, int m, int **A);
void initializePenalty(int n, int m, int **penalty);
void fillPenalty(int n, int m, int **A, int **penalty);
void printPenalty(int n, int m, int **penalty);

#endif 

