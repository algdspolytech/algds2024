#include "CountingTheWays.h"

int main() {
	int n = 3;
	int k = 100;
	int* result = (int*)malloc(sizeof(int) * (n + 1));
	result[0] = 1;
	for (int i = 1; i < n + 1; i++) {
		result[i] = 0;
	}
	CountingTheWays(result, n, k);
	printf("%i ways", result[n]);
	free(result);
	return 0;
}