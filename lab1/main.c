   #include <stdio.h>
   #include "matrix_operations.h"

   int main() {
       int n, m;
       readMatrixSize(&n, &m);

       int A[n][m];
       int penalty[n][m];

       readMatrix(n, m, A);
       initializePenalty(n, m, penalty);
       fillPenalty(n, m, A, penalty);
       printPenalty(n, m, penalty);

       return 0;
   }
   
