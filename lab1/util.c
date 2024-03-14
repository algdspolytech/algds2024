#include "util.h"

int min1(int a, int b) {
    return (a < b) ? a : b;
}
graph* createGraph(int n, int edges[][3], int edgesSize) {
    graph* obj = (graph*)malloc(sizeof(graph));
    obj->n = n;
    obj->adj = (int**)calloc(n, sizeof(int*));
    obj->cost = (int*)calloc(n, sizeof(int));
    obj->visited = (bool*)calloc(n, sizeof(bool));

    for (int i = 0; i < n; i++) {
        obj->adj[i] = (int*)calloc(n, sizeof(int));
    }

    for (int i = 0; i < edgesSize; i++) {
        graphAddEdge(obj, edges[i]);
    }

    return obj;
}

void graphAddEdge(graph* obj, int* edge) {
    obj->adj[edge[0]][edge[1]] = edge[2];
}

void printGraphAdjMatrix(graph* obj) {
    printf("Матрица смежности графа:\n");
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
void printGraph(graph* obj) {
    if (obj->n == 9) {
        printf("Граф:\n");
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
    else {
        printf("Ошибка. Пока что этим методом можно вывести набор точек с улицами размерности 3x3\n");
    }
}