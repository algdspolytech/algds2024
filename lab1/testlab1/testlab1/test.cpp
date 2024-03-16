#include "pch.h"
#include "..\lab1\main.h"

TEST(TestMinimum1, Test1) {
	EXPECT_EQ(1.00, minimum(1.01, 1.00));
}

TEST(TestMinimum2, Test2) {
	EXPECT_EQ(1.01, minimum(1.01, 1.01));
}

TEST(TestMinimum3, Test3) {
	EXPECT_NE(1.01, minimum(1.00, 1.01));
}

TEST(TestminCost1, Test4) {
	EXPECT_EQ(0, minCost("aaaa", "aaaa", 1, 2, 3));
}

TEST(TestminCost2, Test5) {
	EXPECT_EQ(7, minCost("abcd", "dcba", 1, 2, 3));
}
