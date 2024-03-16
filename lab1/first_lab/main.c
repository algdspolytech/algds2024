#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
		exit(1);
	}

	int n;
	fscanf(f, "%d", &n);

	if (n == 0) {
		printf("No sequence is given");
		exit(2);
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


void readfileTest() {

	list_s* test1 = (list_s*)malloc(sizeof(list_s));
	test1->N = 3;
	int* list1 = (int*)malloc(3 * sizeof(int));
	list1[0] = 1;
	list1[1] = 2;
	list1[2] = 3;
	test1->seq = list1;
	list_s* test1t = readfile("test1.txt");
	if (test1->N != test1t->N) {
		printf("test1 Error");
		exit(1);
	}
	for (int i = 0; i < 3; i++) {
		if (test1->seq[i] != test1t->seq[i]) {
			printf("test1 Error");
			exit(1);
		}
	}

	list_s* test2 = (list_s*)malloc(sizeof(list_s));
	test2->N = 4;
	int* list2 = (int*)malloc(4 * sizeof(int));
	list2[0] = 1;
	list2[1] = 2;
	list2[2] = 2;
	list2[3] = 1;
	test2->seq = list2;
	list_s* test2t = readfile("test2.txt");
	if (test2->N != test2t->N) {
		printf("test2 Error");
		exit(1);
	}
	for (int i = 0; i < 4; i++) {
		if (test2->seq[i] != test2t->seq[i]) {
			printf("test2 Error");
			exit(1);
		}
	}


	list_s* test3 = (list_s*)malloc(sizeof(list_s));
	test3->N = 1;
	int* list3 = (int*)malloc(sizeof(int));
	list3[0] = 8;
	test3->seq = list3;
	list_s* test3t = readfile("test3.txt");
	if (test3->N != test3t->N) {
		printf("test3 Error");
		exit(1);
	}
	for (int i = 0; i < 1; i++) {
		if (test3->seq[i] != test3t->seq[i]) {
			printf("test3 Error");
			exit(1);
		}
	}

	printf("readfileTest OK\n");
}


int main() {

	readfileTest();

	list_s* list = readfile("input.txt");

	list_s* result = function(list->seq, list->N);

	for (int i = 0; i < result->N; i++) {
		printf("%d ", result->seq[i]);
	}

	return 0;
}
