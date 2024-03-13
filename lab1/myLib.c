#include "myLib.h"

int min(int a, int b) {
    return a < b ? a : b;
}// Функция для нахождения минимума
graph* createGraph(){
    graph* myGraph = malloc(sizeof(graph));
    myGraph->vertices_len = 0;
    myGraph->vertices_size = 4;
    myGraph->vertices = malloc(myGraph->vertices_size * sizeof(vertex*));
    for (int i = 0; i < 16; i++) {
        myGraph->vertices[i] = malloc(sizeof(vertex));
    }
    printf("hello");
    return myGraph;
}


void fillGraphWithVertices(graph* myGraph, int m, int n) {

}

void addEdgesToNearestVertices(graph* myGraph, int m, int n) {

}

// Функция для добавления вершины в граф
void addVertex(graph* myGraph) {
    if (myGraph->vertices_len < myGraph->vertices_size) {
        vertex* newVertex = malloc(sizeof(vertex));
        newVertex->edges_len = 0;
        newVertex->edges_size = 4;
        newVertex->edges = malloc(newVertex->edges_size * sizeof(edge*));

        myGraph->vertices[myGraph->vertices_len] = newVertex;
        myGraph->vertices_len++;
    }
    else {
        // Увеличить размер массива вершин, если необходимо
        // Например, с помощью realloc()
    }
}

// Функция для добавления ребра к вершине
void addEdgeToVertex(graph* myGraph, int vertexIndex, int targetVertex, int weight) {
    if (vertexIndex < myGraph->vertices_len) {
        vertex* someVertex = myGraph->vertices[vertexIndex];
        if (someVertex->edges_len < someVertex->edges_size) {
            edge* newEdge = malloc(sizeof(edge));
            newEdge->vertex = targetVertex;
            newEdge->weight = weight;

            someVertex->edges[someVertex->edges_len] = newEdge;
            someVertex->edges_len++;
        }
        else {
            // Увеличить размер массива ребер, если необходимо
            // Например, с помощью realloc()
        }
    }
}

// Функция для освобождения памяти графа
void freeGraph(graph* myGraph) {
    for (int i = 0; i < myGraph->vertices_len; i++) {
        vertex* currentVertex = myGraph->vertices[i];
        for (int j = 0; j < currentVertex->edges_len; j++) {
            free(currentVertex->edges[j]);
        }
        free(currentVertex->edges);
        free(currentVertex);
    }
    free(myGraph->vertices);
    free(myGraph);
}


void printGraph(graph* myGraph) {
    for (int i = 0; i < myGraph->vertices_len; i++) {
        printf("Вершина %d:\n", i);
        for (int j = 0; j < myGraph->vertices[i]->edges_len; j++) {
            printf("  Ребро к вершине %d, вес %d\n", myGraph->vertices[i]->edges[j]->vertex, myGraph->vertices[i]->edges[j]->weight);
        }
        printf("\n");
    }
}

