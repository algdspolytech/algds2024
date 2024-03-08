#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdlib.h> 
#include "Header.h"
void ans(int A, int n) {

	int* b;
	int* c;
	int* ans;
	int** mas;
	ans = malloc(sizeof(int) * n);
	b = getarray(n);
	c = getarray(n);
	mas = creatematrix(b, c, A, n);
	findans(n, A, mas, b,ans);
}
int main() {

#if 0
	int A;
	int n;
	scanf("%d %d", &A, &n);
	ans(A, n);
#endif	
	int b[5] = { 3,4 };
	int c[5] = { 1,6 };
	int** mas = creatematrix(&b[0], &c[0], 2, 2);
	int ans[2] = { 0 };
	findans(2, 2, (const int**)mas, &b[0], &ans[0]);
	for (int i = 0; i <= 2; ++i) {
		for (int j = 0; j <= 3; ++j) {
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}

	
	for (int i = 0; i < 2; ++i) {
		printf("%d ", ans[i]);
	}
	

	
}