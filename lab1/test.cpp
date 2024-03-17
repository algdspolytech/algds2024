//
// Created by nick on 10.03.2024.
//
#include <gtest/gtest.h>
#include "main.h"

void test_get_distance_0(){
    struct Point a = {0, 0}, b = {0, 0};
    double expected = 0;
    double actual = get_distance(a, b);
    EXPECT_EQ(expected, actual);
}

void test_get_distance_0_5(){
    struct Point a = {0, 0}, b = {0, 5};
    double expected = 5;
    double actual = get_distance(a, b);
    EXPECT_EQ(expected, actual);
}

void test_get_distance_3_4(){
    struct Point a = {0, 4}, b = {0, 3};
    double expected = 5;
    double actual = get_distance(a, b);
    EXPECT_EQ(expected, actual);
}

void test_arra_min_index_345(){
    double v[] = {3, 4, 5};
    unsigned size = 3;
    unsigned expected = 3;
    unsigned actual = array_min_index(v, size);
    EXPECT_EQ(expected, actual);
}

void test_arra_min_index__123(){
    double v[] = {-1, -2, -3};
    unsigned size = 3;
    unsigned expected = 2;
    unsigned actual = array_min_index(v, size);
    EXPECT_EQ(expected, actual);
}

void test_get_max_345(){
    double v[] = {3, 4, 5};
    unsigned size = 3;
    double expected = 5;
    double actual = get_max(v, size);
    EXPECT_EQ(expected, actual);

    void test_get_max_(){
        double v[] = {-1,-2,1,2};
        unsigned size = 4;
        double expected = 2;
        double actual = get_max(v, size);
        EXPECT_EQ(expected, actual);
    }

    void test_initPoints_0(){
        unsigned n = 0;
        struct Point *array = initPoints(&n);
        EXPECT_EQ(0, n);
        EXPECT_EQ(nullptr, array);
    }

    void test_initPoints_4(){
        unsigned n = 0;
        struct Point *array = initPoints(&n);
        EXPECT_NE(nullptr, array);
    }
