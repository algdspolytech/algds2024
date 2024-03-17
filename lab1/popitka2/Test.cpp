#include "gtest/gtest.h"
#include <string.h>
#include <stdlib.h>
#include "FileName.h"
#include "FileName.c"

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}


TEST(check_sum_, Handles_Zero_positive_numbers) {
    EXPECT_EQ(1, check_sum(4, 3, 3, 4));
    EXPECT_EQ(1, check_sum(0, 0, 0, 0));
    EXPECT_EQ(1, check_sum(2, 3, 3, 2));
    EXPECT_EQ(0, check_sum(4, 3, 4, 2));
    EXPECT_EQ(0, check_sum(3, 15, 2, 3));
}
TEST(recursion_search_, Handles_Zero_positive_numbers) {
    EXPECT_EQ(6, recursion_search(3, 2, 0, 0,0));
    EXPECT_EQ(16, recursion_search(5, 2, 0, 2, 10));
    EXPECT_EQ(646, recursion_search(6, 20, 0, 2, 13));
    EXPECT_EQ(1, recursion_search(0, 0, 0, 0, 0));
}
TEST(kolvo_number_, Handles_Zero_positive_numbers) {
    EXPECT_EQ(6, kolvo_number(3, 2));
    EXPECT_EQ(56, kolvo_number(4, 5));
    EXPECT_EQ(1340, kolvo_number(5, 11));
    EXPECT_EQ(0, kolvo_number(2, 100));
    EXPECT_EQ(1, kolvo_number(0, 0));
    
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}