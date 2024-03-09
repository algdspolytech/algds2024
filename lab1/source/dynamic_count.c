#include "dynamic_count.h"

DynamicTable setupDynamicTable(size_t n, size_t k) {
	DynamicTable dynamicTable = malloc(sizeof(size_t*) * n);

	if (dynamicTable != NULL) {
		for (size_t currentn = 0; currentn < n; currentn++) {
			dynamicTable[currentn] = malloc(sizeof(size_t) * (k + 1));

			if (dynamicTable[currentn] == NULL) {
				return NULL;
			}

			dynamicTable[currentn][0] = 1;
		}

		for (size_t currentk = 0; currentk <= k; currentk++) {
			if (currentk < 10) {
				dynamicTable[0][currentk] = 1;
			}
			else {
				dynamicTable[0][currentk] = 0;
			}
		}
	}

	return dynamicTable;
}

void freeDynamicTable(DynamicTable dynamicTable, size_t n, size_t k) {
	if (n != 0 && k != 0) {
		size_t d, b = 0;

	}
	for (size_t currentn = 0; currentn < n; currentn++) {
		free(dynamicTable[currentn]);
	}
}

size_t countNumbers(size_t n, size_t k)
{
	if (9 * n < k || n <= 0 || k < 0) {
		return 0;
	}

	size_t numbersCount = 0;

	DynamicTable dynamicTable = setupDynamicTable(n, k);

	if (dynamicTable == NULL) {
		return 0;
	}

	for (size_t currentn = 1; currentn < n; currentn++) {
		for (size_t currentk = 1; currentk <= k; currentk++) {
			numbersCount = 0;
			for (size_t digit = 0; digit <= currentk && digit <= 9; digit++) {
				numbersCount += dynamicTable[currentn - 1][currentk - digit];
			}
			dynamicTable[currentn][currentk] = numbersCount;
		}
	}
	numbersCount = dynamicTable[n - 1][k];

	freeDynamicTable(dynamicTable, n, k);

	return numbersCount;
}
