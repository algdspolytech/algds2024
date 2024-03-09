#include "Lab1_lcs.h"
int** create_matrix(int rows, int cols) {
    int** matrix;
    if ((matrix = (int**)malloc(rows * sizeof(int*))) == NULL)
        return NULL;
    for (int i = 0; i < rows; i++) {
        if ((matrix[i] = (int*)malloc(cols * sizeof(int))) == NULL)
            return NULL;
    }
    return matrix;
}
void delete_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
void print_LCS(int** matrix_B, char* arr_X, char* str, int i, int j, int start) {
    static int length;
    if (start) {
        length = 0;
        *(str + length) = "";
    }
    if ((i == 0) || (j == 0)) {
        return;
    }
    if (matrix_B[i][j] == 1) {
        print_LCS(matrix_B, arr_X, str, i - 1, j - 1, 0);
        length += sprintf(str + length, "%c", arr_X[i - 1]);
    }
    else if (matrix_B[i][j] == 2) {
        print_LCS(matrix_B, arr_X, str, i - 1, j, 0);
    }
    else {
        print_LCS(matrix_B, arr_X, str, i, j - 1, 0);
    }
}
char* LCS_Length(char* arr_X, char* arr_Y) {
    int length_X = strlen(arr_X)+1;
    int length_Y = strlen(arr_Y)+1;
    int** matrix_C;
    int** matrix_B;
    matrix_C = create_matrix(length_X, length_Y);
    matrix_B = create_matrix(length_X, length_Y);
    for (int i = 1; i < length_X; i++) {
        matrix_C[i][0] = 0;
        matrix_B[i][0] = 0;
    }
    for (int i = 0; i < length_Y; i++) {
        matrix_C[0][i] = 0;
        matrix_B[0][i] = 0;
    }
    for (int i = 1; i < length_X; i++) {
        for (int j = 1; j < length_Y; j++) {
            if (*(arr_X + i - 1) == *(arr_Y + j - 1)) {
                matrix_C[i][j] = matrix_C[i - 1][j - 1] + 1;
                matrix_B[i][j] = 1;
            }
            else if (matrix_C[i - 1][j] >= matrix_C[i][j - 1]) {
                matrix_C[i][j] = matrix_C[i - 1][j];
                matrix_B[i][j] = 2;
            }
            else {
                matrix_C[i][j] = matrix_C[i][j - 1];
                matrix_B[i][j] = 3;
            }
        }
    }
    int max = matrix_C[length_X - 1][length_Y - 1];
    char* max_str;
    if ((max_str = (char*)malloc((size_t)max + 1)) == NULL)
        return NULL;
    print_LCS(matrix_B, arr_X, max_str, length_X - 1, length_Y - 1, 1);
    max_str[max] = 0;
    delete_matrix(matrix_C, length_X);
    delete_matrix(matrix_B, length_X);
    //for (int i = 0; i < max; i++) {
    //    printf("%c", max_str[i]);
    //}
    return max_str;
}
