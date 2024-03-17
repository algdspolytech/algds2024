#pragma once
#include <stdio.h>
#include <stdlib.h>

void CountingTheWays(int* result, int step, int k) {//step = N
	if (step == 0) return;
	for (int i = 1; i <= k; i++) {
		if (step - i < 0) break;
		if ((result)[step - i] == 0) CountingTheWays(result, step - i, k);
		(result)[step] += (result)[step - i];
	}
}