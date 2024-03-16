#include "util.h"

graph* createGraph(int n, int edges[][3], int edgesSize) {
    if (n <= 0 || edges == NULL || edgesSize <= 0) {
        printf("Ошибка: неверные входные данные для создания графа.\n");
        return NULL;
    }
    graph* obj = (graph*)malloc(sizeof(graph));
    obj->n = n;
    obj->adj = (int**)calloc(n, sizeof(int*));

    for (int i = 0; i < n; i++) {
        obj->adj[i] = (int*)calloc(n, sizeof(int));
    }

    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][0] < 0 || edges[i][0] >= n || edges[i][1] < 0 || edges[i][1] >= n) {
            printf("Ошибка: неверные данные ребра.\n");
            freeGraph(obj);
            return NULL;
        }
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
#define INF INT_MAX

int graphShortestPath(graph* obj, int start, int target) {
    if (obj == NULL || start < 0 || start >= obj->n || target < 0 || target >= obj->n) {
        printf("Ошибка: неверные входные данные для поиска кратчайшего пути.\n");
        return -1;
    }

    // Создание и инициализация матрицы расстояний
    int** dist = (int**)malloc(obj->n * sizeof(int*));
    for (int i = 0; i < obj->n; i++) {
        dist[i] = (int*)malloc(obj->n * sizeof(int));
        for (int j = 0; j < obj->n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (obj->adj[i][j] != 0)
                dist[i][j] = obj->adj[i][j];
            else
                dist[i][j] = INF;
        }
    }

    // алгоритма Флойда-Уоршелла для поиска кратчайших путей
    for (int k = 0; k < obj->n; k++) {
        for (int i = 0; i < obj->n; i++) {
            for (int j = 0; j < obj->n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }


    int shortestPathCost = dist[start][target];

    // Освобождение выделенной памяти
    for (int i = 0; i < obj->n; i++) {
        free(dist[i]);
    }
    free(dist);

    return shortestPathCost == INF ? -1 : shortestPathCost;
}
void printGraph(graph* obj) {
    if (obj == NULL) {
        printf("Ошибка: неинициализированный граф.\n");
        return;
    }
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