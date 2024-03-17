#ifndef MASSIV_BEST_PRIORITY_FUNC_H
#define MASSIV_BEST_PRIORITY_FUNC_H
int ** dynamic_array_alloc (size_t N, size_t M);
void dynamic_array_free(int **A,size_t N);
int min(int a, int b);
int findMinPenalty(int **A, int n, int m) ;
#endif
