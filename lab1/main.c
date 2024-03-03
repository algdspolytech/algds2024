#include <stdio.h>

#include "framework.h"
#include "test.h"

void main() {
	TEST(19, "tests_folder/test1.txt");
	TEST(0, "tests_folder/test2.txt");
	TEST(20, "tests_folder/test3.txt");
	TEST(0, "tests_folder/test4.txt");
	TEST(16, "tests_folder/test5.txt");
}
