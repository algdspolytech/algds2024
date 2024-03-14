#include <gtest/gtest.h>

extern "C" {
    #include "util.h"
}
TEST(Test, BasicAssertions) {
    int n = 9;
    int edges[][3] = {
        {0, 1, 3}, {0, 3, 2},
        {1, 2, 5}, {1, 4, 7},
        {2, 5, 2},
        {3, 4, 2}, {3, 6, 4},
        {4, 5, 1}, {4, 7, 2},
        {5, 8, 7},
        {6, 7, 6},
        {7, 8, 4}
    };
    int edgesSize = 12;
    graph* myGraph = createGraph(n, edges, edgesSize);
    int shortestPathCost = graphShortestPath(myGraph, 0, 1);

    // ќжидаемый результат - 13 (сумма весов ребер пути 0->1->4->7->8)
    EXPECT_EQ(shortestPathCost, 3);
    freeGraph(myGraph);
}
