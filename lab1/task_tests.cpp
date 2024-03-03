#include <gtest/gtest.h>

extern "C" {
	#include "FieldRoutesCalculate.h"
}

TEST(calculateRoutesToEndTest, InvalidFieldSize) {
	EXPECT_EQ(calculateRoutesToEnd(-1, 1), -1);
}

TEST(calculateRoutesToEndTest, InvalidMaxStepLength) {
	EXPECT_EQ(calculateRoutesToEnd(1, -1), -1);
}

TEST(calculateRoutesToEndTest, SingularValues) {
	EXPECT_EQ(calculateRoutesToEnd(1, 1), 1);
}

TEST(calculateRoutesToEndTest, MaxStepLongerFieldSize) {
	EXPECT_EQ(calculateRoutesToEnd(2, 3), 2);
}

TEST(calculateRoutesToEndTest, FieldSizeLongerMaxStep) {
	EXPECT_EQ(calculateRoutesToEnd(3, 2), 3);
}
