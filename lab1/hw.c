#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable: 4996)
#include "hw.h"

/*������� ������: ������ ������� �� �����
1�� ������ - n
������ - m
����� ������ - ��� ������ ������� �

�������� ������:
����� - ����������� �����*/

int main() {
	system("chcp 1251");
	setlocale(LC_CTYPE, "Russian");
	//�������� ����� ��� ������
	FILE* file = fopen("matrix.txt", "r");
	CheckFopen(file);
	//������ �������
	int row, col;
	int** matrix;
	CheckFscanf(fscanf(file, "%d\n%d", &row, &col));
	matrix = ReadMatrix(file, row, col);
	Fclose(file);

	int min = FindMinFine(matrix, row, col);
	printf("������ ������������ ������ : %d\n���� ��������� �������, ��������� ������� ������\n", min);
	FreeMatrix(matrix, row);
	return 0;
}