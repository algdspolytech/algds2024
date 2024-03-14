#include"util.h"


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

    // Создание графа
    graph* myGraph = createGraph(n, edges, edgesSize);

    // Вывод графа
    printGraphAdjMatrix(myGraph);

    printGraph(myGraph);

    // Поиск кратчайшего пути между 
    int shortestPathCost;
    int a = -1, b = -1;
    printf("Введите от какой точки до какой найти минимальное расстояние:\n");
    while (scanf("%d %d", &a, &b) == 2){
        shortestPathCost = graphShortestPath(myGraph, a, b);
        if (shortestPathCost != -1) {
            printf("Ближайший путь между точкой %d и точкой %d: %d\n",a,b, shortestPathCost);
        }
        else {
            printf("Не найдено пути между точкой %d и точкой %d\n",a, b);
        }
        printf("Введите две точки:\n");
    }
    // Освобождение памяти
    freeGraph(myGraph);

    return 0;
}

