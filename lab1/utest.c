#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
void test__min_time() {
	if (min_time("test0.txt") == 21) {
		printf("test0.txt has been processed normally\n\n");
	}
	else {
		printf("mistake in test0.txt processing\n\n");
		exit(16);
	}
	if (min_time("test1.txt") == 3) {
		printf("test1.txt has been processed normally\n\n");
	}
	else {
		printf("mistake in test1.txt processing\n\n");
		exit(16);
	}
	if (min_time("test2.txt") == 0) {
		printf("test2.txt has been processed normally\n\n");
	}
	else {
		printf("mistake in test2.txt processing\n\n");
		exit(16);
	}
	if (min_time("test3.txt") == -1) {
		printf("test3.txt has been processed normally\n\n");
	}
	else {
		printf("mistake in test3.txt processing\n\n");
		exit(16);
	}
}