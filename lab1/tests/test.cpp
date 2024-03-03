#include "gtest/gtest.h"
#include "main.h"

TEST(test, t1) {
    int n = 3;
    int k = 100;
    int res = 0;
    ASSERT_EQ(res, Count_number(n, k));
}

TEST(test, t2) {
    int n = 5;
    int k = 0;
    int res = 1;
    ASSERT_EQ(res, Count_number(n, k));
}

TEST(test, t3) {
    int n = 0;
    int k = 1000;
    int res = 0;
    ASSERT_EQ(res, Count_number(n, k));
}

TEST(test, t4) {
    int n = 3;
    int k = 7;
    int res = 36;
    ASSERT_EQ(res, Count_number(n, k));
}