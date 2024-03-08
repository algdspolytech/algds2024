#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdlib.h> 
#include "Header.h"
int* ans(int A, int n) {

	int* b;
	int* c;
	int* ans;
	int** mas;
	ans = calloc (n,sizeof(int));
	b = getarray(n);
	c = getarray(n);
	mas = creatematrix(b, c, A, n);
	findans(n, A, mas, b,ans);
	for (int i = 0; i <= n; ++i) {
		free(mas[i]);
	}
	free(mas);
	free(b);
	free(c);
	return ans;
}
int main() {

#
	int A;
	int n;
	int* res;
	scanf("%d %d", &A, &n);
	
	res = ans(A, n);



	
}