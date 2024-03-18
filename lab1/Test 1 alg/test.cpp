#include "pch.h"
#include "../ALG 1.6/CountingTheWays.h"

TEST(CountingTheWaysTest, CountingTheWays_n3k2_3Returned) {
    // arrange
    int n = 3, k = 2;
    int* result = (int*)malloc(sizeof(int) * (n + 1));
    result[0] = 1;
    for (int i = 1; i < n + 1; i++) {
        result[i] = 0;
    }
    int expected = 3;

    // act
    CountingTheWays(result, n, k);
    int actual = result[n];

    // assert
    ASSERT_EQ(expected, actual);
}

TEST(CountingTheWaysTest, CountingTheWays_n3k100_4Returned) {
    // arrange
    int n = 3, k = 100;
    int* result = (int*)malloc(sizeof(int) * (n + 1));
    result[0] = 1;
    for (int i = 1; i < n + 1; i++) {
        result[i] = 0;
    }
    int expected = 4;

    // act
    CountingTheWays(result, n, k);
    int actual = result[n];

    // assert
    ASSERT_EQ(expected, actual);
}

TEST(CountingTheWaysTest, CountingTheWays_n3k1_1Returned) {
    // arrange
    int n = 3, k = 1;
    int* result = (int*)malloc(sizeof(int) * (n + 1));
    result[0] = 1;
    for (int i = 1; i < n + 1; i++) {
        result[i] = 0;
    }
    int expected = 1;

    // act
    CountingTheWays(result, n, k);
    int actual = result[n];

    // assert
    ASSERT_EQ(expected, actual);
}