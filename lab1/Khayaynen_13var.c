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
	
	printf("\nИтоговый массив\n\n%d\n", a[MaxIndex]);
	
	while (MaxIndex != 0) {

		MaxIndex = c[MaxIndex];
		printf("%d\n", a[MaxIndex]);

	} 
	free(b);
}

void Tests(int n)
{
	
		printf("1. Тест на то, если в массиве 1 элемент\n");
		int m = 1;
		int* a = malloc(m * sizeof(int));
		a[0] = 1;
		SortedAndDeleting(a, m);
		free(a);
		printf("\n");

		printf("2. Тест на то, если в массиве элементы в обратном порядке\n");
		m = 5;
		a = malloc(m * sizeof(int));
		printf("Массив = ");
		for (int i = 0;i < m; i++)
		{
			a[i] = 5 - i;
			printf("%d ", a[i]);
		}
		
		SortedAndDeleting(a, m);
		free(a);
		printf("\n");

		printf("3. Тест на то, если в массиве сначала идет длинная последовательность, а потом короткая, но номинал у короткой больше + есть повторения\n");
		m = 13;
		int b[13] = {1,2,2,2,4,5,6,3,4,7,8,9,6};
		printf("Массив = {1,2,2,2,4,5,6,3,4,7,8,9,6}\n");
		SortedAndDeleting(b, m);
		printf("\n");
	
}

int main()
{
	int n,k=0;
	setlocale(LC_CTYPE, "Rus");
	Tests(k);
	printf("Введите длину массива\n\n");
	scanf("%d", &n);
	printf("\n");

	if (n == 0) {
		printf("Введите больше элементов\n");
		exit(1);
	}
	printf("Введите массив\n\n");
	int* a = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == " " || a[i] == '\0') {
			exit(1);
			printf("Ошибка");
		}
	}
	
	printf("\n\n\n");
	SortedAndDeleting(a,n);
	free(a);
	return 0;
}