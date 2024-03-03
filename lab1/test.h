#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "framework.h"

void TEST(int result, char* test_name) {
	const FILE* file = OpenFile(test_name, "r");
	Data data;
	Init(file, &data);
	CloseFile(file);

	clock_t start_time = clock();
	int r = Finder(data);
	clock_t end_time = clock();

	if (result == r) {
		printf("test passed!\n");
		printf("function working time: %d sec\n", (end_time - start_time) / CLOCKS_PER_SEC);
	}
	else {
		printf("test failed!\n");
	}
}

void testOpenFile() {
    FILE* file = OpenFile("test_file.txt", "r");
    if (file) {
        printf("testOpenFile: Passed\n");
        CloseFile(file);
    }
    else {
        printf("testOpenFile: Failed\n");
    }
}