#include "pch.h"
#include "../dynamic_progr/hw.h"

int rand_row = 2;
int rand_col = 3;
int** rand_matrix = AllocMatrix(rand_row, rand_col);

TEST(TestMainFunc, TwoSamePaths) {
	//making matrix for a test
	for (int i = 0; i < rand_row; i++) {
		rand_matrix[i][0] = 1;
		rand_matrix[i][1] = 2;
		rand_matrix[i][2] = 1;
	}

	ASSERT_EQ(FindMinFine(rand_matrix, rand_row, rand_col), 2);
}

TEST(TestMainFunc, EmptyMatrix) {
	int** matrix = NULL;
	ASSERT_EQ(FindMinFine(matrix, 2, 3), 0);
	free(matrix);
}

TEST(TestMainFunc, WrongDimensions) {
	ASSERT_EQ(FindMinFine(rand_matrix, -1, 0), 0);
	free(rand_matrix);
}

TEST(TestHelpFunc, EmptyLine) {
	int* array = NULL;
	ASSERT_EQ(FindMinInLine(array, 0), 0);
	free(array);
}
