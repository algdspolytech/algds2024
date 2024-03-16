#include "gtest/gtest.h"
extern "C" {
    #include "matrix_operations.h"
}

TEST(MatrixOperationsTest, MinPenaltyTest) {
    // Произвольная матрица
    int** matrix1 = allocate_matrix(2, 4);
    matrix1[0][0] = 1; matrix1[0][1] = 3; matrix1[0][2] = 1; matrix1[0][3] = 5;
    matrix1[1][0] = 2; matrix1[1][1] = 2; matrix1[1][2] = 4; matrix1[1][3] = 1;
    EXPECT_EQ(min_penalty(matrix1, 2, 4), 4);
    free_matrix(matrix1, 2);

    // Матрица 1х1
    int** matrix2 = allocate_matrix(1, 1);
    matrix2[0][0] = 5;
    EXPECT_EQ(min_penalty(matrix2, 1, 1), 5);
    free_matrix(matrix2, 1);

    // Матрица 1xn
    int** matrix3 = allocate_matrix(1, 5);
    matrix3[0][0] = 1; matrix3[0][1] = 2; matrix2[0][2] = 3; matrix2[0][3] = 4; matrix2[0][4] = 5;
    EXPECT_EQ(min_penalty(matrix2, 1, 5), 1 + 2 + 3 + 4 + 5); 
    free_matrix(matrix2, 1);

    // Матрица nx1
    int** matrix4 = allocate_matrix(4, 1);
    matrix4[0][0] = 1; matrix4[1][0] = 2; matrix4[2][0] = 3; matrix4[3][0] = 4;
    EXPECT_EQ(min_penalty(matrix4, 4, 1), 1 + 2 + 3 + 4); 
    free_matrix(matrix4, 4);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}