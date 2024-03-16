#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

int** allocate_matrix(int rows, int cols);
void free_matrix(int** matrix, int rows);
void input_matrix_dimensions(int* rows, int* cols);
void input_matrix_elements(int** matrix, int rows, int cols);
int min_penalty(int** matrix, int rows, int cols);

#endif 