#define _CRT_SECURE_NO_WARNINGS
#define N 20
#include "funcs.h"

enum action {
	DEL = 1,
	INP,
	CHANGE,
	HOLD,
	START
};

struct Cell {
	int cost;
	action act;
};

void ScanCoef(int* d, int* i, int* c) {
	*d = 0;
	while (*d == 0.0) {
		printf("\nEnter coefficient 'd': ");
		scanf_s("%d", d);
	}
	*i = 0;
	while (*i == 0.0) {
		printf("\nEnter coefficient 'i': ");
		scanf_s("%d", i);
	}
	*c = 0;
	while (*c == 0.0) {
		printf("\nEnter coefficient 'c': ");
		scanf_s("%d", c);
	}
	getchar();
}
void DeleteSym(char* stringX, int i) { //удал€ет i-ый символ, работает
	char dstr1[N];
	char dstr2[N];
	strncpy(dstr1, stringX, (i - 1));
	dstr1[i - 1] = '\0';
	strcpy(dstr2, &stringX[i]);
	strcat(dstr1, dstr2);
	strcpy(stringX, dstr1);
}

void InputSym(char* stringX, int i, char* sym) { //вставл€ет символ перед i-тым (мб нужно пусто после символа)
	char str1[N];
	char str2[N];
	strncpy(str1, stringX, (i - 1));
	str1[i - 1] = '\0';
	strcpy(str2, &stringX[i - 1]);
	strcat(str1, sym);
	strcat(str1, str2);
	strcpy(stringX, str1);
}

void FindSol(char* stringX, char* stringY, int del, int inp, int change) {
	int m = (int)(strlen(stringX) - 1);
	int n = (int)(strlen(stringY) - 1);
	Cell Mat[N][N];
	for (int i = 0; i <= m; i++) {
		Mat[i][0].cost = i * del;
		Mat[i][0].act = DEL;
	}
	for (int i = 0; i <= n; i++) {
		Mat[0][i].cost = i * inp;
		Mat[0][i].act = INP;
	}
	Mat[0][0].act = START;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int c = 0;
			if (stringX[i - 1] != stringY[j - 1]) c = change; //смотрим одинаковые ли символы
			if ((Mat[i - 1][j].cost + del) <= (Mat[i - 1][j - 1].cost + c)) { //если точно не замена
				if ((Mat[i - 1][j].cost + del) <= (Mat[i][j - 1].cost + inp)) { //если удаление
					Mat[i][j].cost = Mat[i - 1][j].cost + del;
					Mat[i][j].act = DEL;
				}
				else { //если вставка
					Mat[i][j].cost = Mat[i][j - 1].cost + inp;
					Mat[i][j].act = INP;
				}
			}
			else { //если точно не удаление
				if ((Mat[i][j - 1].cost + inp) <= (Mat[i - 1][j - 1].cost + c)) { //если вставка
					Mat[i][j].cost = Mat[i][j - 1].cost + inp;
					Mat[i][j].act = INP;
				}
				else {
					if (c != 0) { //если смена
						Mat[i][j].cost = Mat[i - 1][j - 1].cost + c;
						Mat[i][j].act = CHANGE;
					}
					else {
						Mat[i][j].cost = Mat[i - 1][j - 1].cost; //если равные
						Mat[i][j].act = HOLD;
					}
				}
			}
		}
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d ", Mat[i][j].cost);
		}
		printf("\n");
	}

	int i = m;
	int j = n;
	int counter = 0;
	action Steps[N * 2];
	while (!((i == 0) && (j == 0))) { //ѕробегаемс€ назад по цепочке - записываем шаги
		Steps[counter] = Mat[i][j].act;
		if (Steps[counter] == DEL) {
			i = i - 1;
		}
		if (Steps[counter] == INP) {
			j = j - 1;
		}
		if ((Steps[counter] == HOLD) || (Steps[counter] == CHANGE)) {
			i = i - 1;
			j = j - 1;

		}
		counter = counter + 1;
	}
	Steps[counter] = START;
	int lendif = 0; //учЄт сдвига при действии
	for (int k = (counter); k >= 0; k = k - 1) {
		if (Steps[k] == DEL) {
			i = i + 1;
			printf("delete %c\n", stringX[i + lendif - 1]);
			DeleteSym(stringX, (i + lendif));
			puts(stringX);
			lendif = lendif - 1;
		}
		if (Steps[k] == INP) {
			j = j + 1;
			printf("input %c\n", stringY[j - 1]);
			char buf[2];
			buf[0] = stringY[j - 1];
			buf[1] = '\0';
			InputSym(stringX, (i + 1 + lendif), buf);
			puts(stringX);
			lendif = lendif + 1;
		}
		if (Steps[k] == HOLD) {
			i = i + 1;
			j = j + 1;
		}
		if (Steps[k] == CHANGE) {
			printf("change %c to %c\n", stringX[i + lendif], stringY[j]);
			stringX[i + lendif] = stringY[j];
			i = i + 1;
			j = j + 1;
			puts(stringX);
		}
		if (Steps[k] == START) puts(stringX);
	}
}
