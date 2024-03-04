#include "../Project10/Lab1.h"
#include <gtest/gtest.h>
#include <limits.h>
TEST(solveTest, HandleNotSame) {
    double A[4][3] = { {5, 7, 8},{3, 2, 5}, {5, 7, 9}, {4, 6, 7} };
    double B[3][4] = { {5, 6, 7, 6},{2, 4, 5, 4},{3, 2, 5, 2} };
    ASSERT_EQ(solve(A, B), 21);
}
TEST(solveTest, Empty) {
    double A[4][3] = {};
    double B[3][4] = {};
    ASSERT_EQ(solve(A, B), NULL);
}
TEST(solveTest, Same) {
    double A[4][3] = { {1, 1, 1},{1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
    double B[3][4] = { {1, 1, 1, 1},{1, 1, 1, 1}, {1, 1, 1, 1} };
    ASSERT_EQ(solve(A, B), 6);
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
