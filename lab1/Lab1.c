#pragma warning <disable:4996>
#include<stdio.h>
#include<stdlib.h>
#include "Lab1.h"
#define MIN(a,b) (((a)<(b))?(a):(b))

int main() {
	double A[4][3] = { {1, 1, 1},{1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
	double B[3][4] = { {1, 1, 1, 1},{1, 1, 1, 1}, {1, 1, 1, 1} };
	printf("%lf ",solve(A, B));
	
}