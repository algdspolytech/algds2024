#include "pch.h"
#include "C:\Users\User\CLionProjects\doublerTest2\algds2024\lab1\HelloTestSuite2\HelpFunc.c"

TEST(TestCaseName, TestName) {
  char name[20] = "TestName1.txt";

  EXPECT_EQ(5, FindCountMax(name));

  EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName2) {
	char name[20] = "TestName2.txt";

	EXPECT_EQ(4, FindCountMax(name));

	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName3) {
	char name[20] = "TestName3.txt";

	EXPECT_EQ(1, FindCountMax(name));

	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName4) {
	char name[20] = "TestName4.txt";

	EXPECT_EQ(3, FindCountMax(name));

	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName5) {
	char name[20] = "TestName5.txt";

	EXPECT_EQ(5, FindCountMax(name));

	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName6) {
	char name[20] = "TestName6.txt";

	EXPECT_EQ(0, FindCountMax(name));

	EXPECT_TRUE(true);
}


