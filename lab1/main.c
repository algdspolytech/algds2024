#include <stdio.h>
void printArr(int* arr, int size_column, int size_row){
    printf("\n");
    for(int i = 0; i < size_column; i++){
        for(int j = 0; j < size_row; j++){
            printf("%d ", arr[i*size_column+j]);
        }
        printf("\n");
    }
}
int intMin(int a, int b){
    if (a < b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int n, m;
    scanf_s("%d %d", &n, &m);
    int **costs =(int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        costs[i] =(int*)malloc(m*sizeof(int));
    }

    for(int i = 0; i < n; i++){
        int* row = (int*) malloc(m * sizeof(int));
        for(int j = 0; j < m; j++){
            int cost;
            scanf_s("%d", &cost);
            row[j] = cost;
        }
        costs[i] = row;
    }
    int **dp =(int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        dp[i] =(int*)malloc(m*sizeof(int));
    }
    //printArr(&dp[0][0], n, m);
    
    dp[n-1][0] = costs[n-1][0];
    for(int i = 1; i < m; i++){

        dp[n-1][i] = dp[n-1][i-1] + costs[n-1][i]; 
        //printf("%d %d %d\n", n-1, i, dp[n-1][i]);
    }
    for(int i = n-2; i >= 0; i--){
        dp[i][0] = dp[i+1][0] + costs[i][0]; 
        //printf("%d %d %d\n", i, 0, dp[n-1][i]);
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = 1; j < m; j++){
            dp[i][j] = intMin(dp[i+1][j], dp[i][j-1]) + costs[i][j];
            //printf("%d %d %d\n", i, j, dp[i][j]);
        }
    }
    //printArr(&dp[0][0], n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("%d", dp[0][0]);
    return 0;
}
