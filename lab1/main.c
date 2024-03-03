#include "FieldRoutesCalculate.h"

int main() {
	int N, K;
	printf("input N, K: ");
	scanf_s("%d %d", &N, &K);
	printf("%d", calculateRoutesToEnd(N, K));
	return 0;
}