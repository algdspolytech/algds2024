#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <cassert>

typedef struct list_s {
	int* seq;
	int N;
}list_s;


list_s* readfile(char const* filename) {

	list_s* result = (list_s*)malloc(sizeof(list_s));
	FILE* f;

	f = fopen(filename, "r");
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

	result->N = n;
	result->seq = list;

	fclose(f);

	return result;
}



list_s* function(int const* list, int const n) {

	list_s* result = (list_s*)malloc(sizeof(list_s));

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

	int* res = (int*)malloc(max_sum * sizeof(int));
	for (int i = max_start; i <= max_finish; i++) {
		res[i - max_start] = list[i];
	}

	result->N = max_sum;
	result->seq = res;

	return result;
}

int main() {
	list_s* list = readfile("input.txt");

	list_s* result = function(list->seq, list->N);

	for (int i = 0; i < result->N; i++) {
		printf("%d ", result->seq[i]);
	}

	return 0;
}
