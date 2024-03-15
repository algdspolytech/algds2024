#include <stdio.h>
void printArr(int** arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n, m;
    scanf_s("%d %d", &n, &m);
    int** costs = (int**) malloc(n * m * sizeof(int));
    for(int i = 0; i < n; i++){
        int* row = (int*) malloc(m * sizeof(int));
        for(int j = 0; j < m; j++){
            int cost;
            scanf_s("%d", &cost);
            row[j] = cost;
        }
        costs[i] = row;
    }
    printArr(costs, n);    
}