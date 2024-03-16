#include <gtest/gtest.h>

extern "C" {
    #include "util.h"
}
// ���� ��� ������� �������� �����
TEST(create_graph, basic_case) {
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

    // ��������, ��� ��������� ���� �� ����� nullptr
    EXPECT_NE(myGraph, nullptr);

    // ��������, ��� ���������� ������ � ����� ������������� ����������
    EXPECT_EQ(myGraph->n, n);

    // ��������, ��� ����� ��������� ���������
    for (int i = 0; i < edgesSize; ++i) {
        int src = edges[i][0];
        int dst = edges[i][1];
        int weight = edges[i][2];
        EXPECT_EQ(myGraph->adj[src][dst], weight);
    }

    // ������������ ������
    freeGraph(myGraph);
}

// ���� ��� ������� ������ ����������� ���� � �����
TEST(find_graph_shortest_path, basic_case) {
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

    // ����� ����������� ���� ����� ������� 0 � 1
    int shortestPathCost = graphShortestPath(myGraph, 0, 3);

    EXPECT_EQ(shortestPathCost, 2);

    // ������������ ������
    freeGraph(myGraph);
}

TEST(find_graph_shortest_path, no_way_case) {
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

    // ����� ����������� ���� ����� ������� 0 � 1
    int shortestPathCost = graphShortestPath(myGraph, 1, 3);

    // ��������� ��������� - 13 (����� ����� ����� ���� 0->1->4->7->8)
    EXPECT_EQ(shortestPathCost, -1);

    // ������������ ������
    freeGraph(myGraph);
}

// ���� ��� ������� ���������� ����� � ����
TEST(graphAddEdgeTest, basic_case) {
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

    // ���������� ����� � ����
    int newEdge[] = { 0, 2, 4 };
    graphAddEdge(myGraph, newEdge);

    // ��������, ��� ����� ��������� ���������
    EXPECT_EQ(myGraph->adj[newEdge[0]][newEdge[1]], newEdge[2]);

    // ������������ ������
    freeGraph(myGraph);
}
// ������������ ������� ������ ����������� ��������� ����
TEST(min_cost, basic_case) {
    int cost[] = { 10, 20, 5, 15 };
    bool visited[] = { false, false, false, false };
    int n = 4;

    int minNode = minCost(cost, visited, n);

    // �������, ��� ����������� ��������� ����� � ���� � �������� 2
    ASSERT_EQ(minNode, 2);
}