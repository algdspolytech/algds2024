#include <gtest/gtest.h>
extern "C" {
    #include "matrix_operations.h"
}

TEST(fillPenaltyTest, ValidInput) {
    
    const int n = 3;
    const int m = 3;

    int **A = (int**)malloc(n * sizeof(int*));
    int **penalty = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(m * sizeof(int));
        penalty[i] = (int*)malloc(m * sizeof(int));
    }

    // Заполняем массив A
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
    A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;

    initializePenalty(n, m, penalty);
    fillPenalty(n, m, A, penalty);

    EXPECT_EQ(penalty[0][0], 1);
    EXPECT_EQ(penalty[0][1], 2);
    EXPECT_EQ(penalty[0][2], 3);
    EXPECT_EQ(penalty[1][0], 5); // Минимальное значение из (1, 2) + 4
    EXPECT_EQ(penalty[1][1], 6); // Минимальное значение из (1, 2, 3) + 5
    EXPECT_EQ(penalty[1][2], 8); // Минимальное значение из (2, 3) + 6
    EXPECT_EQ(penalty[2][0], 12); // Минимальное значение из (5, 6) + 7
    EXPECT_EQ(penalty[2][1], 13); // Минимальное значение из (5, 6, 8) + 8
    EXPECT_EQ(penalty[2][2], 15); // Минимальное значение из (6, 8) + 9
    
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(penalty[i]);
    }
    free(A);
    free(penalty);
}

