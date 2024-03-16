#define _CRT_SECURE_NO_WARNINGS
#define N 20
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"


int main() {
	int del, inp, change;
	ScanCoef(&del, &inp, &change);
	char stringX[N];
	char stringY[N];
	printf("\nEnter string X:");
	fgets(stringX, N, stdin);
	printf("\nEnter string Y:");
	fgets(stringY, N, stdin);
	printf("\nString X: ");
	puts(stringX);
	printf("\nString Y: ");
	puts(stringY);
	FindSol(stringX, stringY, del, inp, change);
	return 0;
}
