#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <locale.h>

typedef struct {
    int** adj;
    int n;
    int* cost;
    bool* visited;
} graph;

graph* createGraph(int n, int edges[][3], int edgesSize, int* edgesColSize);
void graphAddEdge(graph* obj, int* edge, int edgeSize);
void printGraphAdjMatrix(graph* obj);
void freeGraph(graph* obj);
void printNamedGraph(graph* obj);
int graphShortestPath(graph* obj, int node1, int node2);
int minCost(int* cost, bool* visited, int n);


int main() {
    setlocale(LC_ALL, "Rus");
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
    int edgesColSize[] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

    // �������� �����
    graph* myGraph = createGraph(n, edges, edgesSize, edgesColSize);

    // ����� �����
    printGraphAdjMatrix(myGraph);

    printNamedGraph(myGraph);

    // ����� ����������� ���� ����� 
    int shortestPathCost;
    int a = -1, b = -1;
    printf("������� �� ����� ����� �� ����� ����� ����������� ����������:\n");
    while (scanf("%d %d", &a, &b) == 2){
        shortestPathCost = graphShortestPath(myGraph, a, b);
        if (shortestPathCost != -1) {
            printf("��������� ���� ����� ������ %d � ������ %d: %d\n",a,b, shortestPathCost);
        }
        else {
            printf("�� ������� ���� ����� ������ %d � ������ %d\n",a, b);
        }
        printf("������� ��� �����:\n");
    }
    // ������������ ������
    freeGraph(myGraph);

    return 0;
}

graph* createGraph(int n, int edges[][3], int edgesSize, int* edgesColSize) {
    graph* obj = malloc(sizeof(graph));
    obj->n = n;
    obj->adj = (int**)calloc(n, sizeof(int*));
    obj->cost = (int*)calloc(n, sizeof(int));
    obj->visited = (bool*)calloc(n, sizeof(bool));

    for (int i = 0; i < n; i++) {
        obj->adj[i] = (int*)calloc(n, sizeof(int));
    }

    for (int i = 0; i < edgesSize; i++) {
        graphAddEdge(obj, edges[i], edgesColSize[i]);
    }

    return obj;
}

void graphAddEdge(graph* obj, int* edge, int edgeSize) {
    if (edgeSize >= 3) {
        obj->adj[edge[0]][edge[1]] = edge[2];
    }
}

void printGraphAdjMatrix(graph* obj) {
    printf("Adjacency matrix of graph:\n");
    for (int i = 0; i < obj->n; i++) {
        for (int j = 0; j < obj->n; j++) {
            
            printf("%d ", obj->adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void freeGraph(graph* obj) {
    for (int i = 0; i < obj->n; i++) {
        free(obj->adj[i]);
    }
    free(obj->adj);
    free(obj->cost);
    free(obj->visited);
    free(obj);
}
int minCost(int* cost, bool* visited, int n)
{
    int min = INT_MAX, min_node = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == false && cost[i] <= min) {
            min = cost[i];
            min_node = i;
        }
    }

    return min_node;
}
int graphShortestPath(graph* obj, int node1, int node2) {

    for (int i = 0; i < obj->n; i++) {
        obj->cost[i] = INT_MAX,
            obj->visited[i] = false;
    }

    obj->cost[node1] = 0;

    /* Dijkstra's Algorithm */
    for (int i = 0; i < obj->n - 1; i++) {

        int src = minCost(obj->cost, obj->visited, obj->n);

        obj->visited[src] = true;

        for (int dst = 0; dst < obj->n; dst++)
            if (obj->visited[dst] == false && obj->adj[src][dst]
                && obj->cost[src] != INT_MAX
                && obj->cost[src] + obj->adj[src][dst] < obj->cost[dst]) {

                obj->cost[dst] = obj->cost[src] + obj->adj[src][dst];
            }
    }

    return obj->cost[node2] == INT_MAX ? -1 : obj->cost[node2];
}
void printNamedGraph(graph* obj) {
    printf("Graph:\n");
    printf("(0)-%d-(1)-%d-(2)\n", obj->adj[0][1], obj->adj[1][2]);
    printf(" |     |     |\n");
    printf(" %d     %d     %d\n", obj->adj[0][3], obj->adj[1][4], obj->adj[2][5]);
    printf(" |     |     |\n");
    printf("(3)-%d-(4)-%d-(5)\n", obj->adj[3][4], obj->adj[4][5]);
    printf(" |     |     |\n");
    printf(" %d     %d     %d\n", obj->adj[3][6], obj->adj[4][7], obj->adj[5][8]);
    printf(" |     |     |\n");
    printf("(6)-%d-(7)-%d-(8)\n", obj->adj[6][7], obj->adj[7][8]);
    printf("\n");
}