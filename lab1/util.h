#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h> 
#include <stdbool.h>
#include <locale.h>

typedef struct {
    int** adj;
    int n;
    int* cost;
    bool* visited;
} graph;

graph* createGraph(int n, int edges[][3], int edgesSize);
void graphAddEdge(graph* obj, int* edge);
void printGraphAdjMatrix(graph* obj);
void freeGraph(graph* obj);
void printGraph(graph* obj);
int graphShortestPath(graph* obj, int node1, int node2);
int minCost(int* cost, bool* visited, int n);

#endif