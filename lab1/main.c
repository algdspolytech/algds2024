#include <stdio.h> 
#include "myLib.h" 

int main() {
    graph* matrixGraph = createGraph();
    
    freeGraph(matrixGraph);
    return 0;
}