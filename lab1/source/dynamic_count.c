#include "dynamic_count.h"

DynamicTable setupDynamicTable(int n, int k) {
	DynamicTable dynamicTable = malloc(sizeof(int*) * (n + 1));

	if (dynamicTable != NULL) {
		for (int currentn = 0; currentn <= n; currentn++) {
			dynamicTable[currentn] = malloc(sizeof(int) * (k + 1));

			if (dynamicTable[currentn] == NULL) {
				return NULL;
			}

			dynamicTable[currentn][0] = 1;
		}

		for (int currentk = 0; currentk <= k; currentk++)
			dynamicTable[0][currentk] = 0;
	}

	return dynamicTable;
}

void freeDynamicTable(DynamicTable dynamicTable, int n, int k) {
	if (n != 0 && k != 0) {
		int d, b = 0;

	}
	for (int currentn = 0; currentn <= n; currentn++) {
		free(dynamicTable[currentn]);
	}
}

int сountNumbers(int n, int k)
{
	int numbersCount = 0;

	DynamicTable dynamicTable = setupDynamicTable(n, k);

	if (dynamicTable == NULL) {
		return 0;
	}

	for (int currentn = 1; currentn <= n; currentn++) {
		for (int currentk = 1; currentk <= k; currentk++) {
			dynamicTable[currentn][currentk] = dynamicTable[currentn - 1][currentk] + dynamicTable[currentn][currentk - 1];
		}
	}
	numbersCount = dynamicTable[n][k];

	freeDynamicTable(dynamicTable, n, k);

	return numbersCount;
}
