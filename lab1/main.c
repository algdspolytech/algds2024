#include <stdio.h>

#include "framework.h"
#include "test.h"

void main() {
	const FILE* file = OpenFile("tests_folder/test1.txt", "r");
	Data data;
	Init(file, &data);
	CloseFile(file);

	TEST_MAX_SUMMARY();
	TEST_FINDER(82, "tests_folder/test1.txt");
	TEST_FINDER(0, "tests_folder/test2.txt");
	TEST_FINDER(76, "tests_folder/test3.txt");
	TEST_FINDER(0, "tests_folder/test4.txt");
	TEST_FINDER(10000, "tests_folder/test5.txt");
}