#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void print_table(int** table,int n, int m) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m*4;j++) {
			printf("%d", table[i][j]);
			if ((j+1) % 4 != 0 ) {
				printf(" ");
			}
			if ((j+1) % 4 == 0) {
				printf(";");
			}
		}
		if (i != n - 1) {
			printf("\n");
		}
	}
}
void print_sol_table(int** sol, int n, int m) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			printf("%d ",sol[i][j]);
		}
		printf("\n");
	}
}
int** read_table(char* path,int* p,int* g) {
	FILE* f;
	f = fopen(path,"r");
	if (f == NULL) {
		printf("File %s is not found", path);
		exit(10);
	}
	int n, m, c=0;
	char* buf;

	fscanf(f, "%d %d", &n,&m);
	buf = malloc(sizeof(char) * (8 * m+1));
	int** table = malloc(sizeof(int*) * n);

	for (int i = 0;i < n;i++) {
		c = 0;
		
		fread(buf, sizeof(char), 8 * m + 1, f);
		if (feof(f)) {
			printf("Incorrect input: file %s\n", path);
			return -1;
		}
		table[i] = malloc(sizeof(int) * 4 * m);
		for (int k = 0;k < strlen(buf);k++) {
			if (buf[k] > 47 && buf[k] < 58) {
				table[i][c] = (int)buf[k] - 48;
				c++;
			}
		}
	}
	*p = n;
	*g = m;
	return table;
}

int min_time(char* path) {
	int n=0, m=0;
	int* p = &n;
	int* q = &m;
	int** table = read_table(path, p, q);
	if (table == -1) {
		return -1;
	}
	int** dynamic = malloc(sizeof(int*) * (n+1));
	for (int i = 0;i < n+1;i++) {
		dynamic[i] = malloc(sizeof(int) * (m+1));
		for (int j = 0;j < m+1;j++) {
			dynamic[i][j] = 0;
		}
	}
	for (int j = 1;j < m+1;j++) {
		dynamic[0][j] = table[0][4*(j-1)+3] + dynamic[0][j - 1];
	}
	for (int i = 1;i < n + 1;i++) {
		dynamic[i][0] = table[i-1][0] + dynamic[i - 1][0];
	}

	for (int i = 1;i < n+1;i++) {
		for (int j = 1;j < m+1;j++) {
			dynamic[i][j] = min(dynamic[i - 1][j] + table[i - 1][(j-1) * 4 + 1], dynamic[i][j - 1] + table[i-1][(j - 1) * 4 + 2]);
		}
	}

	return dynamic[n][m];
}

int main() {
	test__min_time();
	return 0;
}