#ifndef HELPFUNC_H
#define HELPFUNC_H
#include <stdio.h> 

typedef struct {
    int vertex;
    int weight;
} edge_t;

typedef struct {
    edge_t** edges;
    int edges_len;
    int edges_size;
    int dist;
    int prev;
    int visited;
} vertex_t;

typedef struct {
    vertex_t** vertices;
    int vertices_len;
    int vertices_size;
} graph_t;

typedef struct {
    int* data;
    int* prio;
    int* index;
    int len;
    int size;
} heap_t;

int min(int a, int b);

void printMatrix(int m, int n, int** A);

#endif