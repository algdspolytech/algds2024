#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "Header.h"

int Max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int Find_Max_Path(int** board, int N) {
	setlocale(LC_CTYPE, "RUSSIAN");
	if (N == 0) {
		//printf("\nДоски не существует.\n\n");
		return 0;
	}
	int** newboard = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		newboard[i] = (int*)malloc(N * sizeof(int));
	}
	//первая строка остается той же
	for (int i = 0; i < N; i++) {
		newboard[N - 1][i] = board[N - 1][i];
	}
	//заполняем newboard
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if ((j != 0) && (j != N - 1)) {
				newboard[i][j] = board[i][j] + Max(newboard[i + 1][j - 1], Max(newboard[i + 1][j], newboard[i + 1][j + 1]));
			}
			else if (j == 0) {
				newboard[i][j] = board[i][j] + Max(newboard[i + 1][j], newboard[i + 1][j + 1]);
			}
			else {
				newboard[i][j] = board[i][j] + Max(newboard[i + 1][j - 1], newboard[i + 1][j]);
			}
		}
	}
	//максимальный в последнем ряду
	int maxpath = -100000;
	int* index = (int*)malloc(N * sizeof(int));
	index[0] = 0;
	for (int i = 0; i < N; i++) {
		if (newboard[0][i] > maxpath) {
			maxpath = newboard[0][i];
			index[0] = i;
		}
	}
	//собираем номера элементов в строках, чтобы потом составить путь
	for (int i = 1; i < N; i++) {
		if (index[i - 1] == 0) {
			if (newboard[i][index[i - 1]] > newboard[i][index[i - 1] + 1]) {
				index[i] = index[i - 1];
			}
			else {
				index[i] = index[i - 1] + 1;
			}
		}
		else if (index[i - 1] == N - 1) {
			if (newboard[i][index[i - 1]] > newboard[i][index[i - 1] - 1]) {
				index[i] = index[i - 1];
			}
			else {
				index[i] = index[i - 1] - 1;
			}
		}
		else {
			if (Max(newboard[i][index[i - 1] - 1], newboard[i][index[i - 1]]) > newboard[i][index[i - 1] + 1]) {
				if (newboard[i][index[i - 1] - 1] > newboard[i][index[i - 1]]) {
					index[i] = index[i - 1] - 1;
				}
				else {
					index[i] = index[i - 1];
				}
			}
			else {
				index[i] = index[i - 1] + 1;
			}
		}
	}
	//вывод пути и его максимальное значение
	/*printf("\nПуть: ");
	for (int i = 0; i < N; i++) {
		if (i != N - 1) {
			printf("(%d,%d) -> ", index[N - i - 1] + 1, i + 1);
		}
		else {
			printf("(%d,%d)\n", index[N - i - 1] + 1, i + 1);
		}
	}
	printf("\nМаксимальный путь: %d\n\n", maxpath);*/

	for (int i = 0; i < N; i++) {
		free(newboard[i]);
	}
	free(newboard);
	free(index);

	return maxpath;
}
