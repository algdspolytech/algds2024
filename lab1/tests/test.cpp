#include "gtest/gtest.h"
#include "main.h"

TEST(test, t1) {
    Point t1 = {0, 0}, t2 = {0, 5};
    float answer = 5.0f;
    ASSERT_EQ(answer, Distance(t1, t2));
}

TEST(test, t2) {
    Point t3 = {-1, 6}, t4 = {-1, -4};
    float answer = 10.0f;
    ASSERT_EQ(answer, Distance(t3, t4));
}

TEST(test, t3) {
    int N = 25;
    int j = N - 1, i = 0;
    float answer = 0.f;
    ASSERT_EQ(answer, Check(i, j, N));
}

TEST(test, t4) {
    int N = 6;
    int j = 0, i = N - 1;
    float answer = 0;
    ASSERT_EQ(answer, Check(i, j, N));
}

TEST(test, t5) {
    int pos_point;
    const int N = 5;
    Point arr[N] = {{0, 0},
                    {2, 0},
                    {3, 0.8},
                    {4, 2},
                    {1, 3}};
    float answer = 2;
    Result(&pos_point, arr, N);
    ASSERT_EQ(answer, pos_point);
}

TEST(test, t6) {
    int pos_point;
    const int N = 6;
    Point arr[N] = {{-1, -1},
                    {1,  -1},
                    {2,  0},
                    {1,  2},
                    {-1, 3},
                    {-2, 1}};
    float answer = 3;
    Result(&pos_point, arr, N);
    ASSERT_EQ(answer, pos_point);
}
