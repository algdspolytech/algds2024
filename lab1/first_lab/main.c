#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void function(int const* list, int const n) {

	int start = 0, finish = 0, max_sum = 1, current_sum = 1, max_start = 0, max_finish = 0;

	for (int i = 0; i < n; i++) {
		if (list[i + 1] % list[i] == 0) {
			current_sum += 1;
			finish = i + 1;
		}
		else {
			if (current_sum > max_sum) {
				max_sum = current_sum;
				max_start = start;
				max_finish = finish;
			}
			current_sum = 1;
			start = i + 1;
			finish = i + 1;

		}
	}

	int* result = (int*)malloc(max_sum * sizeof(int));
	for (int i = max_start; i <= max_finish; i++) {
		result[i - max_start] = list[i];
	}

	for (int i = 0; i < max_sum; i++) {
		printf("%d ", result[i]);
	}

	return 0;
}

int main() {

	FILE* f;
	f = fopen("input.txt", "r");
	if (f == NULL) {
		printf("Errors occured while reading file");
		exit(0);
	}

	int n;
	fscanf(f, "%d", &n);

	if (n == 0) {
		printf("No sequence is given");
		exit(0);
	}
	int* list = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d", &list[i]);
	}
	fclose(f);

	function(list, n);


	return 0;
}
