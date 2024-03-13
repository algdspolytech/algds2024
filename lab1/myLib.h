#ifndef HELPFUNC_H
#define HELPFUNC_H
#include <stdio.h> 
#include <stdbool.h>
typedef struct {
    int vertex;
    int weight;
} edge;

typedef struct {
    edge** edges;
    int edges_len;
    int edges_size;
} vertex;

typedef struct {
    vertex** vertices;
    int vertices_len;
    int vertices_size;
} graph;

// Функция для инициализации графа
graph* createGraph();
void fillGraphWithVertices(graph* myGraph, int m, int n);

void addEdgesToNearestVertices(graph* myGraph, int m, int n);

// Функция для добавления вершины в граф
void addVertex(graph* myGraph); 

// Функция для добавления ребра к вершине
void addEdgeToVertex(graph* myGraph, int vertexIndex, int targetVertex, int weight);

// Функция для освобождения памяти графа
void freeGraph(graph* myGraph);

void printGraph(graph* myGraph);

int min(int a, int b);


#endif