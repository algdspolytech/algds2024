#include "gtest/gtest.h"
#include "../Test/Method.h"

TEST(test, t1) {
    int n = 2;
    int k = 20;
    int res = 0;
    ASSERT_EQ(res, Amount(n, k));
}

TEST(test, t2) {
    int n = 2;
    int k = 3;
    int res = 4;
    ASSERT_EQ(res, Amount(n, k));
}

TEST(test, t3) {
    int n = 10;
    int k = 0;
    int res = 1;
    ASSERT_EQ(res, Amount(n, k));
}

TEST(test, t4) {
    int n = 0;
    int k = 1;
    int res = 0;
    ASSERT_EQ(res, Amount(n, k));
}