#include "pch.h"
#include "C:\Users\ikane\OneDrive\Документы\GitHub\algds2024\lab1\helloTest\dyn_prog.cpp"

/*TEST(TestCaseName, TestName) {
  EXPECT_EQ(6, doubler(3));
  EXPECT_TRUE(true);
} */

/*TEST(Based_case, 1) {
	EXPECT_EQ(10, doubler(5));
	EXPECT_TRUE(true);
} */

TEST(Based_case, 1) {
	int n = 3, A = 2;
	int b[] = { 0,0,2,1 }, c[] = { 0,9,8,14 };
	int p = 0;
	int ans = 13;
	EXPECT_EQ(ans, findSubset(n, A, &p, b, c));
	EXPECT_TRUE(true);
}

TEST(SameCost_case, 1) {
	int n = 5, A = 10;
	int b[] = { 0,2,6,1,3,3 }, c[] = { 0,7,7,7,7,7 };
	int p = 0;
	int ans = 1345;
	EXPECT_EQ(ans, findSubset(n, A, &p, b, c));
	EXPECT_TRUE(true);
}

TEST(OwerWeight_case, 1) {
	int n = 3, A = 5;
	int b[] = { 0,10,20,30 }, c[] = { 0,6,6,6 };
	int p = 0;
	int ans = 0;
	EXPECT_EQ(ans, findSubset(n, A, &p, b, c));
	EXPECT_TRUE(true);
}

TEST(Empty_case, 1) {
	int n = 3, A = 5;
	int b[] = { 0 }, c[] = { 0 };
	int p = 0;
	int ans = 0;
	EXPECT_EQ(ans, findSubset(n, A, &p, b, c));
	EXPECT_TRUE(true);
}