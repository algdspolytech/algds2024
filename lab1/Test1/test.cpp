#include "pch.h"
#include "C:\Users\nasty\3D Objects\Цифровой практикум\CloneRep1\algds2024\lab1\Project1\Function.c"

TEST(Count_Numbers_With_Sum_K, Positiv_Numbers) {
	EXPECT_EQ(2, CountNumbersWithSumK(2, 1));
	EXPECT_EQ(3, CountNumbersWithSumK(3, 1));
	EXPECT_EQ(6, CountNumbersWithSumK(3, 2));
}

TEST(Count_Numbers_With_Sum_K, Negatin_Numbers) {
	EXPECT_EQ(0, CountNumbersWithSumK(-2, 1));
	EXPECT_EQ(0, CountNumbersWithSumK(3, -1));
	EXPECT_EQ(0, CountNumbersWithSumK(-3, -2));
}

TEST(Count_Numbers_With_Sum_K, Null_Numbers) {
	EXPECT_EQ(0, CountNumbersWithSumK(0, 1));
	EXPECT_EQ(1, CountNumbersWithSumK(3, 0));
	EXPECT_EQ(0, CountNumbersWithSumK(0, 0));
}