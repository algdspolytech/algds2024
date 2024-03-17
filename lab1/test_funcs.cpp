#include <gtest\gtest.h>
extern "C"{
    #include "funcs.h"
}

TEST(findMinTimeTest, CostsIsSquare){
    const int n = 3;
    const int m = 3;
    int** costs = createMatrix(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            costs[i][j] = j+1;
        }
    }
    int ans = findMinTime(costs, n, m);
    EXPECT_EQ(ans, 8);
}
TEST(findMinTimeTest, CostsIsRectangle){
    const int n = 3;
    const int m = 4;
    int** costs = createMatrix(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            costs[i][j] = j+1;
        }
    }
    int ans = findMinTime(costs, n, m);
    EXPECT_EQ(ans, 12);
}
TEST(findMinTimeTest, CostsIsOne){
    const int n = 1;
    const int m = 1;
    int** costs = createMatrix(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            costs[i][j] = j+1;
        }
    }
    int ans = findMinTime(costs, n, m);
    EXPECT_EQ(ans, 1);
}