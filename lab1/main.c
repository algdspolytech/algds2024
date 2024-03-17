#include <stdio.h>
#include "funcs.h"

int main(){
    int n, m;
    scanf_s("%d %d", &n, &m);
    int **costs = createMatrix(n, m);

    for(int i = 0; i < n; i++){
        int* row = (int*) malloc(m * sizeof(int));
        for(int j = 0; j < m; j++){
            int cost;
            scanf_s("%d", &cost);
            row[j] = cost;
        }
        costs[i] = row;
    }
    int res = findMinTime(costs, n, m);
    printf("Answer: %d", res);
    return 0;
}
