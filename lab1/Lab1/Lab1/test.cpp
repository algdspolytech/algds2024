#include "pch.h"
#include "..\Algorithm\main.h"

//tests for distance function
TEST(test, t1) {
    Point p1 = { 0, 0 }, p2 = { 4, 0 };
    ASSERT_NE(10, distance(p1, p2));
}

TEST(test, t2) {
    Point p1 = { 0, 0 }, p2 = { 3, 4 };
    ASSERT_EQ(5, distance(p1, p2));
}

//tests for Triangulation function
TEST(test, t3) {
    const int n = 4;
    Point points[n] = { {0, 0},
                     {2, 2},
                     {3, 2},
                     {4, 0} };
    double** res = Triangulation(points, n);
    ASSERT_EQ(2 * sqrt(2), res[0][n - 1]);
}

TEST(test, t4) {
    const int n = 5;
    Point points[n] = { {0, 0},
                        {0, 2},
                        {1, 3},
                        {3, 1},
                        {2, 0} };
    double** res = Triangulation(points, n);
    ASSERT_EQ(2 * sqrt(2), res[0][n - 1]);
}