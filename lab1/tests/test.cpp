#include "gtest/gtest.h"
#include "main.h"

TEST(test, t1) {
    Point t1 = {0, 0}, t2 = {0, 2};
    float result = 2.0f;
    ASSERT_EQ(result, dist(t1, t2));
}

TEST(test, t2) {
    Point t3 = {-1, 0}, t4 = {2, -4};
    float result = 5.0f;
    ASSERT_EQ(result, dist(t3, t4));
}

TEST(test, t3) {
    int n = 6;
    int j = 0, i = n - 1;
    float result = 1;
    ASSERT_EQ(result, proverka(i, j, n));
}

TEST(test, t4) {
    int n = 25;
    int j = n - 1, i = 0;
    float result = 1;
    ASSERT_EQ(result, proverka(i, j, n));
}

TEST(test, t5) {
    int m_d;
    const int n = 5;
    Point obj[n] = {{0,   0},
                    {1,   2},
                    {3,   1},
                    {2,   -1},
                    {0.5, -2}};
    float result = 0;
    finish(&m_d, obj, n);
    ASSERT_EQ(result, m_d);
}

TEST(test, t6) {
    int m_d;
    const int n = 6;
    Point obj[n] = {{0, 0},
                    {0, 2},
                    {1, 4},
                    {2, 4},
                    {4, 3},
                    {4, 1}};
    float result = 1;
    finish(&m_d, obj, n);
    ASSERT_EQ(result, m_d);
}