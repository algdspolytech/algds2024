#include "pch.h"
#include "C:\Users\1\Documents\cplusplus\labs_git\lab1\lab1Test\Project1\variant6.c"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(3, countPaths(3, 2));
	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName2) {
	EXPECT_EQ(0, countPaths(0, 0));
	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName3) {
	EXPECT_EQ(1, countPaths(0, 1));
	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName4) {
	EXPECT_EQ(0, countPaths(1, 0));
	EXPECT_TRUE(true);
}
