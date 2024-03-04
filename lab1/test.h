#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "framework.h"

void TEST_MAX_SUMMARY() {
	printf("max summary tests:\n");
	// ���� 1: ��������, ��� ������� ���������� ���������� ����� ��� ��������� �������
	Thing things1[] = { {2, 3}, {4, 5}, {1, 2} };
	int size1 = sizeof(things1) / sizeof(things1[0]);
	int result1 = MaxSum(things1, size1, 0);
	if (result1 == 28) printf("test passed!\n");
	else printf("test failed!\n");

	// ���� 2: ��������, ��� ������� ���������� sum_before, ���� ����� ������
	Thing things2[] = { {1, 2}, {2, 3}, {3, 4} };
	int size2 = sizeof(things2) / sizeof(things2[0]);
	int result2 = MaxSum(things2, size2, 20);
	if (result2 == 20) printf("test passed!\n");
	else printf("test failed!\n");

	// ���� 3: ��������, ��� ������� ��������� ������������ ������ ������
	Thing* things3 = NULL;
	int result3 = MaxSum(things3, 0, 10);
	if (result3 == 10) printf("test passed!\n");
	else printf("test failed!\n");
}

void TEST_FINDER(int f_result, char* test_name) {
	printf("\nfinder tests:\n");
	const FILE* file = OpenFile(test_name, "r");
	Data data;
	Init(file, &data);
	CloseFile(file);

	int finder_test_rezult = Finder(data);
	if (f_result == finder_test_rezult) printf("test passed!\n");
	else printf("test failed!\n");
}