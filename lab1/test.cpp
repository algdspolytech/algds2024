#include "pch.h"
#include "gtest/gtest.h"
//#include "../Laba1.c"

extern "C" {
#include "../Laba1.c"
}

TEST(CountSumTest, Correct) {
    EXPECT_EQ(1, CountSum(123, 6));
    EXPECT_EQ(1, CountSum(9101, 11));
}

TEST(CountSumTest, Incorrect) {
    EXPECT_EQ(0, CountSum(7853, 13));
    EXPECT_EQ(0, CountSum(43, 9));
}

TEST(ReadNumberTest, Correct) {
    EXPECT_EQ(28, ReadNumber(3, 6));
}

TEST(ReadNumberTest, Incorrect) {
    EXPECT_EQ(0, ReadNumber(1.2, 4));
    EXPECT_EQ(0, ReadNumber('hd', 'j'));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}