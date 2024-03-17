#include <stdio.h>
#include <stdlib.h>

int ** dynamic_array_alloc (size_t N, size_t M)
{
    int **A=(int **)malloc(N*sizeof(int *));
    for (int i=0; i<N; i++) {
        A[i]=(int *)malloc(M*sizeof(int));
    }
    return A;
}
void dynamic_array_free(int **A,size_t N)
{
    for (int i=0;i<N;i++){
        free(A[i]);
    }
    free (A);
}



int min(int a, int b) {
    return (a < b) ? a : b;
}

int findMinPenalty(int **A, int n, int m) {
    
    int **itog =dynamic_array_alloc(n,m);
    for (int j = 0; j < m; j++) {
        itog[0][j] = A[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int left = (j > 0) ? itog[i-1][j-1] : itog[i-1][j];
            int right = (j < m-1) ? itog[i-1][j+1] : itog[i-1][j];
            itog[i][j] = A[i][j] + min(itog[i-1][j], min(left, right));
        }
    }

    int minPenalty = itog[n-1][0];
    for (int j = 1; j < m; j++) {
        minPenalty = min(minPenalty, itog[n-1][j]);
    }
    dynamic_array_free(itog,n);
    return minPenalty;
}

int main() {
    int n, m;


    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int **A =dynamic_array_alloc(n,m);
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]); 
        }
    }

    int minPenalty = findMinPenalty(A, n, m);
    printf("Minimum penalty to reach the last row: %d\n", minPenalty);
    dynamic_array_free(A,n);
    return 0;
}