#include <gtest/gtest.h>
#include "massiv_best_priority_func.h"


TEST(MinPenaltyTest, PositiveNumbers) {
    int **A = dynamic_array_alloc(3, 3);
    A[0][0] = 1;
    A[0][1] = 3;
    A[0][2] = 1;
    A[1][0] = 2;
    A[1][1] = 5;
    A[1][2] = 3;
    A[2][0] = 6;
    A[2][1] = 1;
    A[2][2] = 2;
    
    int result = findMinPenalty(A, 3, 3);
    
    dynamic_array_free(A, 3);
    ASSERT_EQ(result, 4);
}

TEST(MinPenaltyTest, NegativeNumbers) {
    int **A = dynamic_array_alloc(2, 2);
    A[0][0] = -1;
    A[0][1] = -2;
    A[1][0] = -4;
    A[1][1] = -3;
    
    int result = findMinPenalty(A, 2, 2);
    
    dynamic_array_free(A, 2);
    ASSERT_EQ(result, -6);
}

TEST(MinPenaltyTest, ZeroMatrix) {
    int **A = dynamic_array_alloc(1, 1);
    A[0][0] = 0;
    
    int result = findMinPenalty(A, 1, 1);
    
    dynamic_array_free(A, 1);
    ASSERT_EQ(result, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}