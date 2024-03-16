#include <stdio.h>
int intMin(int a, int b){
    if (a < b){
        return a;
    }else{
        return b;
    }
}

int** createMatrix(int const n, int const m){
    int **matrix =(int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        matrix[i] =(int*)malloc(m*sizeof(int));
    }
    return matrix;
}

int findMinTime(int** const costs, int const n, int const m){
    int **dp = createMatrix(n, m);
    
    dp[n-1][0] = costs[n-1][0];
    for(int i = 1; i < m; i++){
        dp[n-1][i] = dp[n-1][i-1] + costs[n-1][i]; 
    }
    for(int i = n-2; i >= 0; i--){
        dp[i][0] = dp[i+1][0] + costs[i][0]; 
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = 1; j < m; j++){
            dp[i][j] = intMin(dp[i+1][j], dp[i][j-1]) + costs[i][j];
        }
    }
    return dp[0][m-1];
}