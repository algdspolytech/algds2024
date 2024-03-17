#pragma once

#include <malloc.h>

typedef int** matrix;

matrix initMatrix(int n, int k);

void destrMatrix(int n, int k, matrix matr);

int solve(int n, int k);
