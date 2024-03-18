#include <gtest/gtest.h>
#include "main.h" 

TEST(MaxCostTest, TestEmptyBoard) {
    int N = 0;
    int** cost = (int**)malloc(N * sizeof(int*));
    EXPECT_EQ(maxCost(cost, N), -1);
    free(cost);
}

TEST(MaxCostTest, TestSingleCellBoard) {
    int N = 1;
    int** cost = (int**)malloc(N * sizeof(int*));
    cost[0] = (int*)malloc(N * sizeof(int));
    cost[0][0] = 5;
    EXPECT_EQ(maxCost(cost, N), 5);
    free(cost[0]);
    free(cost);
}

TEST(MaxCostTest, TestTwoByTwoBoard) {
    int N = 2;
    int** cost = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        cost[i] = (int*)malloc(N * sizeof(int));
    cost[0][0] = 1; cost[0][1] = 2;
    cost[1][0] = 3; cost[1][1] = 4;
    EXPECT_EQ(maxCost(cost, N), 7);
    for (int i = 0; i < N; i++)
        free(cost[i]);
    free(cost);
}

TEST(MaxCostTest, TestThreeByThreeBoard) {
    int N = 3;
    int** cost = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        cost[i] = (int*)malloc(N * sizeof(int));
    cost[0][0] = 1; cost[0][1] = 2; cost[0][2] = 3;
    cost[1][0] = 4; cost[1][1] = 5; cost[1][2] = 6;
    cost[2][0] = 7; cost[2][1] = 8; cost[2][2] = 9;
    EXPECT_EQ(maxCost(cost, N), 23);
    for (int i = 0; i < N; i++)
        free(cost[i]);
    free(cost);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
