#include "gtest/gtest.h"
#include "main.h"

TEST(test, t1) {
    const int N = 5, A = 10;
    int weights[N] = {1, 2, 3, 4, 4};
    int values[N] = {2, 4, 6, 8, 10};
    int answer = 22;
    ASSERT_EQ(answer, Result(N, A, weights, values));
}

TEST(test, t2) {
    const int N = 6, A = 13;
    int weights[N] = {2, 3, 4, 6, 5, 1};
    int values[N] = {5, 1, 4, 6, 3, 8};
    int answer = 23;
    ASSERT_EQ(answer, Result(N, A, weights, values));
}

TEST(test, t3) {
    const int N = 8, A = 11;
    int weights[N] = {2, 1, 3, 5, 1, 8, 3, 4};
    int values[N] = {3, 1, 2, 5, 4, 1, 2, 3};
    int answer = 14;
    ASSERT_EQ(answer, Result(N, A, weights, values));
}

TEST(test, t4) {
    const int N = 3, A = 3;
    int weights[N] = {2, 3, 2};
    int values[N] = {10, 6, 13};
    int answer = 13;
    ASSERT_EQ(answer, Result(N, A, weights, values));
}
