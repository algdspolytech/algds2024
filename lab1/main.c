    #include <stdio.h>
    #include "matrix_operations.h"

    int main() {
        int n, m;
        readMatrixSize(&n, &m);


        int **A = (int**)malloc(n * sizeof(int*));
        int **penalty = (int**)malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++) {
            A[i] = (int*)malloc(m * sizeof(int));
            penalty[i] = (int*)malloc(m * sizeof(int));
        }


        readMatrix(n, m, A);
        initializePenalty(n, m, penalty);
        fillPenalty(n, m, A, penalty);
        printPenalty(n, m, penalty);

        for (int i = 0; i < n; i++) {
                free(A[i]);
                free(penalty[i]);
        }
        free(A);
        free(penalty);
        return 0;
    }
   
