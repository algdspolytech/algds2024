#include "pch.h"
#include <iostream>
#include "C:\Users\User\OneDrive\Документы\GitHub\algds2024\lab1\HelloTestSuite2\HelpFunc.c"


TEST(TestCaseName, TestName) {
	int arr1[5] = {2,4,8,16,32 };

	int array_length = sizeof(arr1) / sizeof(arr1[0]);

  EXPECT_EQ(5, FindCountMax(arr1,array_length));

  EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName2) {
	int arr2[5] = { 0,2,4,8,16 };
	int array_length = sizeof(arr2) / sizeof(arr2[0]);

	EXPECT_EQ(4, FindCountMax(arr2,array_length));

	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName3) {
	int arr3[4] = {3,5,9,15};
	int array_length = sizeof(arr3) / sizeof(arr3[0]);

	EXPECT_EQ(1, FindCountMax(arr3,array_length));

	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName4) {
	int arr4[3] = { 2,4,0 };
	int array_length = sizeof(arr4) / sizeof(arr4[0]);

	EXPECT_EQ(3, FindCountMax(arr4,array_length));

	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName5) {
	int arr5[5] = { -2,4,-8,16,-32 };
	int array_length = sizeof(arr5) / sizeof(arr5[0]);

	EXPECT_EQ(5, FindCountMax(arr5,array_length));

	EXPECT_TRUE(true);
}




