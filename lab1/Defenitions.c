

#include "Header.h"
int* getarray(int n) {
	int* b;
	int res;
	if (n == 0) {
		return NULL;
	}
	b =(int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i) {
		res = scanf("%d", &b[i]);
		if (res != 1) {
			printf("Wrong scanf");
		}
	}
	return b;
}
int**  creatematrix(const int* b, const int* c, const int A,const  int n) {
	if (b == NULL || c == NULL  || n == 0) {
		return NULL;
	}
	int** mas;
	mas = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i < (n + 1); ++i) {
		mas[i] = (int*)malloc(sizeof(int) * (A + 1));
	}
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j <= A; ++j) {
			if (j == 0 || i == 0) {
				mas[i][j] = 0;
				continue;
			}
			if (b[i - 1] > j) {
				mas[i][j] = mas[i - 1][j];
			}
			else {
				if ((mas[i - 1][j - b[i - 1]] + c[i - 1]) >= mas[i - 1][j]) {
					mas[i][j] = mas[i - 1][j - b[i - 1]] + c[i - 1];
				}
				else {
					mas[i][j] = mas[i - 1][j];
				}
			}

		}
	}
	return mas;
}
void findans(int n, int A, const int** mas, const int* b,int* ans) {
	if (mas[n][A] == 0) {
		return;
	}
	if (mas[n][A] == mas[n - 1][A]) {
		findans(n - 1, A, mas, b,ans);
	}
	else {
		findans(n - 1, A - b[n - 1], mas, b,ans);
		ans[n - 1] = n;

		
	}
}