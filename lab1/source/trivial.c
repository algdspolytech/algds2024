#include <stdlib.h>
#include <stdio.h>
#include "trivial.h"

size_t sumOfDigits(Number number, size_t n) {
	size_t sum = 0;

	for (size_t index = 0; index < n; index++) {
		sum += number[index];
	}

	return sum;
}

void printNumber(Number number, size_t n) {
	for (size_t i = 0; i < n; i++) {
		printf("%i ", number[i]);
	}
	printf("\n");
}

size_t countNumberViaEnumRec(Number number, size_t n, size_t k, size_t curDigitIndex) {
	size_t numberCount = 0;

	if (curDigitIndex == n) {
		return 0;
	}

	for (Digit digit = 0; digit <= 9; digit++) {
		number[curDigitIndex] = digit;

		numberCount += countNumberViaEnumRec(number, n, k, curDigitIndex + 1);

		if (curDigitIndex == n - 1 && sumOfDigits(number, n) == k) {
			numberCount++;
		}
	}

	return numberCount;
}

size_t countNumberViaEnum(size_t n, size_t k)
{
	Number number = malloc(sizeof(Digit) * n);

	if (number == NULL) {
		return 0;
	}

	for (size_t i = 0; i < n; i++) {
		number[i] = 0;
	}

	size_t numberCount = countNumberViaEnumRec(number, n, k, 0);

	free(number);

	return numberCount;
}
