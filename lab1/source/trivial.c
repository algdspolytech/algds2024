#include <stdlib.h>

#include "trivial.h"

int sumOfDigits(Number number, int n) {
	int sum = 0;

	for (int index = 0; index < n; index++) {
		sum += number[index];
	}

	return sum;
}

int countNumberViaEnumRec(Number number, int n, int k, int curDigitIndex) {
	int numberCount = 0;

	if (curDigitIndex == n) {
		return 0;
	}

	for (Digit digit = 0; digit <= 9; digit++) {
		number[curDigitIndex] = digit;

		numberCount += countNumberViaEnumRec(number, n, k, curDigitIndex + 1);

		if (sumOfDigits(number, n) == k) {
			numberCount++;
		}
	}

	return numberCount;
}

int countNumberViaEnum(int n, int k)
{
	Number number = malloc(sizeof(Digit) * n);

	if (number == NULL) {
		return 0;
	}

	for (int i = 0; i < n; i++) {
		number[i] = 0;
	}

	int numberCount = countNumberViaEnumRec(number, n, k, 0);

	free(number);

	return numberCount;
}
