#include "pch.h"
#include "C:\Users\overw\Documents\GitHub\algds2024\lab1\[5030102_20001]_Egorkin_lab1\Sourse\Func.c"
TEST(TestCaseName, TestName) {
	int Coord[3][2] = { {0,0},{1,1},{4,2} };
	int n = 3;
  EXPECT_EQ(0, Solution(Coord, n));
  EXPECT_TRUE(true);
}
TEST(TestCaseName, TestName2) {
	int Coord[2][2] = { {0,0},{1,1} };
	int n = 2;
	EXPECT_EQ(-1, Solution(Coord, n));
	EXPECT_TRUE(true);
}
TEST(TestCaseName, TestName3) {
	int Coord[6][2] = { {0,3},{1,6},{4,5},{5,2}, {5,0},{2,0} };
	int n = 6;
	EXPECT_EQ(1, Solution(Coord, n));
	EXPECT_TRUE(true);
}
