#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>




void SortedAndDeleting(int* a, int n)
{
	int max = -821712, MaxIndex = 0;
	int* c = (int*)malloc(sizeof(int) * (n));
	int* b = (int*)malloc(sizeof(int) * (n));
	for (int i = 0; i < n; i++) {
		b[i] = 0;
	}
	
	c[0] = -1;
	c[1] = 0;
	if (n != 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[j] < a[i] && b[i] < b[j] + 1) {
					c[i] = j;
					b[i] = b[j] + 1;
					if (b[i] > max) {
						max = b[i];
						MaxIndex = i;
					}
				}
			}
		}
		
	}
	
	printf("\n�������� ������\n\n%d\n", a[MaxIndex]);
	
	while (MaxIndex != 0) {

		MaxIndex = c[MaxIndex];
		printf("%d\n", a[MaxIndex]);

	} 
	free(b);
}

void Tests(int n)
{
	
		printf("1. ���� �� ��, ���� � ������� 1 �������\n");
		int m = 1;
		int* a = malloc(m * sizeof(int));
		a[0] = 1;
		SortedAndDeleting(a, m);
		free(a);
		printf("\n");

		printf("2. ���� �� ��, ���� � ������� �������� � �������� �������\n");
		m = 5;
		a = malloc(m * sizeof(int));
		printf("������ = ");
		for (int i = 0;i < m; i++)
		{
			a[i] = 5 - i;
			printf("%d ", a[i]);
		}
		
		SortedAndDeleting(a, m);
		free(a);
		printf("\n");

		printf("3. ���� �� ��, ���� � ������� ������� ���� ������� ������������������, � ����� ��������, �� ������� � �������� ������ + ���� ����������\n");
		m = 13;
		int b[13] = {1,2,2,2,4,5,6,3,4,7,8,9,6};
		printf("������ = {1,2,2,2,4,5,6,3,4,7,8,9,6}\n");
		SortedAndDeleting(b, m);
		printf("\n");
	
}

int main()
{
	int n,k=0;
	setlocale(LC_CTYPE, "Rus");
	Tests(k);
	printf("������� ����� �������\n\n");
	scanf("%d", &n);
	printf("\n");

	if (n == 0) {
		printf("������� ������ ���������\n");
		exit(1);
	}
	printf("������� ������\n\n");
	int* a = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == " " || a[i] == '\0') {
			exit(1);
			printf("������");
		}
	}
	
	printf("\n\n\n");
	SortedAndDeleting(a,n);
	free(a);
	return 0;
}