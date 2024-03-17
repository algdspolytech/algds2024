#include <chrono>
#include <gtest/gtest.h>

extern "C" {
#include "func.h"
}

TEST(MAIN_TEST, solve_n0k0_0Returned) {
    // arrange
    int n = 0, k = 0;
    int expected = -1;

    // act
    int actual = solve(n, k);

    // assert
    ASSERT_EQ(expected, actual);
}

TEST(MAIN_TEST, solve_n1k1_1Returned) {
    // arrange
    int n = 1, k = 1;
    int expected = 1;

    // act
    int actual = solve(n, k);

    // assert
    ASSERT_EQ(expected, actual);
}

TEST(MAIN_TEST, solve_n2k17_2Returned) {
    // arrange
    int n = 5, k = 5;
    int expected = 126;

    // act
    int actual = solve(n, k);

    // assert
    ASSERT_EQ(expected, actual);
}

TEST(SUBFUNCTION_TEST, initMatrix_n0k0_NULLReturned) {
    // arrange
    int n = 0, k = 0;
    int** expected = NULL;

    // act
    int** actual = initMatrix(n, k);

    // assert
    ASSERT_EQ(expected, actual);
}
