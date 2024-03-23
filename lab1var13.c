#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void printLongestIncreasingSequence(int* array, int size)
{
	int maxSequenceLength = 0, maxIndex = 0;
	int* lengths = (int*)malloc(sizeof(int) * (size));
	int* previousIndices = (int*)malloc(sizeof(int) * (size));
	for (int i = 0; i < size; i++) {
		lengths[i] = 0;
	}

	lengths[0] = 1;
	previousIndices[0] = -1;
	if (size != 1) {
		for (int i = 1; i < size; i++) {
			for (int j = 0; j < i; j++) {
				if (array[j] < array[i] && lengths[i] < lengths[j] + 1) {
					previousIndices[i] = j;
					lengths[i] = lengths[j] + 1;
					if (lengths[i] > maxSequenceLength) {
						maxSequenceLength = lengths[i];
						maxIndex = i;
					}
				}
			}
		}
	}

	printf("\nНаибольшая последовательность:\n\n%d\n", array[maxIndex]);

	while (maxIndex != 0) {
		maxIndex = previousIndices[maxIndex];
		printf("%d\n", array[maxIndex]);
	}

	free(previousIndices);
	free(lengths);
}

void runTests(int size)
{
	printf("1. Случай с одним элементом в массиве\n");
	int testSize = 1;
	int* testArray = malloc(testSize * sizeof(int));
	testArray[0] = 1;
	printLongestIncreasingSequence(testArray, testSize);
	free(testArray);
	printf("\n");

	printf("2. Убывающая последовательность в массиве\n");
	testSize = 5;
	testArray = malloc(testSize * sizeof(int));
	printf("Массив = ");
	for (int i = 0; i < testSize; i++)
	{
		testArray[i] = 5 - i;
		printf("%d ", testArray[i]);
	}
	printLongestIncreasingSequence(testArray, testSize);
	free(testArray);
	printf("\n");

	printf("3. Пример с повторяющимися элементами и различным порядком, вводится вручную\n");
	testSize = 13;
	int testInput[13] = { 1, 2, 2, 2, 4, 5, 6, 3, 4, 7, 8, 9, 6 };
	printf("Массив = {1, 2, 2, 2, 4, 5, 6, 3, 4, 7, 8, 9, 6}\n");
	printLongestIncreasingSequence(testInput, testSize);
	printf("\n");

}

int main()
{
	int size, userInput = 0;
	setlocale(LC_CTYPE, "Rus");
	runTests(userInput);
	printf("Введите количество элементов в массиве:\n\n");
	scanf("%d", &size);
	printf("\n");

	if (size <= 0) {
		printf("Некорректное количество элементов\n");
		exit(1);
	}
	printf("Введите элементы массива:\n\n");
	int* array = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &array[i]);
		if (array[i] == " " || array[i] == '\0') {
			exit(1);
			printf("Ошибка");
		}
	}

	printf("\n\n\n");
	printLongestIncreasingSequence(array, size);
	free(array);
	return 0;
}
