#include "matrix_operations.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int min_3(int a, int b, int c) {
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

int** allocate_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int*)malloc(cols * sizeof(int));
    return matrix;
}

void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

void input_matrix_dimensions(int* rows, int* cols) {
    printf("Enter the number of rows and columns of the matrix: ");
    scanf_s("%d %d", rows, cols);
}

void input_matrix_elements(int** matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }
}

int min_penalty(int** matrix, int rows, int cols) {
    int** dp = allocate_matrix(rows, cols);

    // Initialize the first row of dp matrix
    for (int j = 0; j < cols; j++)
        dp[0][j] = matrix[0][j];

    // Calculate minimum penalty for each cell
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
            int mid = dp[i - 1][j];
            int right = (j < cols - 1) ? dp[i - 1][j + 1] : INT_MAX;
            dp[i][j] = matrix[i][j] + min_3(left, mid, right);
        }
    }

    // Find the minimum penalty in the last row
    int min_penalty = INT_MAX;
    for (int j = 0; j < cols; j++) {
        if (dp[rows - 1][j] < min_penalty)
            min_penalty = dp[rows - 1][j];
    }

    free_matrix(dp, rows);
    return min_penalty;
}