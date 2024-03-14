#include "pch.h"
#include "../DataDesign1/Lab1.c"


TEST(Maximum_Value, MAX) {
	EXPECT_EQ(3, Max(3, 2));
	EXPECT_EQ(-2, Max(-2, -8));
	EXPECT_EQ(7, Max(7, -2));
	EXPECT_EQ(5, Max(5, 5));
}

TEST(Find_The_Max_Path0, Zero_Board) {
	int N = 0;
	int** board = (int**)malloc(N * sizeof(int*));
	EXPECT_EQ(0, Find_Max_Path(board, N));
	free(board);
}

TEST(Find_The_Max_Path1, One_on_One_Board) {
	int N = 1;
	int** board = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		board[i] = (int*)malloc(N * sizeof(int));
	}
	board[0][0] = 5;

	EXPECT_EQ(5, Find_Max_Path(board, N));

	for (int i = 0; i < N; i++) {
		free(board[i]);
	}
	free(board);
}

TEST(Find_The_Max_Path2, The_Simple_Path) {
	int N = 4;
	int** board = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		board[i] = (int*)malloc(N * sizeof(int));
	}
	board[0][0] = 0; board[0][1] = 6; board[0][2] = 0; board[0][3] = 0;
	board[1][0] = 0; board[1][1] = 0; board[1][2] = 5; board[1][3] = 0;
	board[2][0] = 0; board[2][1] = 4; board[2][2] = 0; board[2][3] = 0;
	board[3][0] = 7; board[3][1] = 0; board[3][2] = 0; board[3][3] = 0;

	EXPECT_EQ(22, Find_Max_Path(board, N));

	for (int i = 0; i < N; i++) {
		free(board[i]);
	}
	free(board);
}

TEST(Find_The_Max_Path3, An_Empty_Board) {
	int N = 4;
	int** board = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		board[i] = (int*)malloc(N * sizeof(int));
	}
	board[0][0] = 0; board[0][1] = 0; board[0][2] = 0; board[0][3] = 0;
	board[1][0] = 0; board[1][1] = 0; board[1][2] = 0; board[1][3] = 0;
	board[2][0] = 0; board[2][1] = 0; board[2][2] = 0; board[2][3] = 0;
	board[3][0] = 0; board[3][1] = 0; board[3][2] = 0; board[3][3] = 0;

	EXPECT_EQ(0, Find_Max_Path(board, N));

	for (int i = 0; i < N; i++) {
		free(board[i]);
	}
	free(board);
}

TEST(Find_The_Max_Path4, The_Random_Board) {
	int N = 5;
	int** board = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		board[i] = (int*)malloc(N * sizeof(int));
	}
	board[0][0] = -12; board[0][1] = 1; board[0][2] = -7; board[0][3] = 8; board[0][4] = 1;
	board[1][0] = 9; board[1][1] = 8; board[1][2] = -5; board[1][3] = 0; board[1][4] = -10;
	board[2][0] = 3; board[2][1] = -2; board[2][2] = 2; board[2][3] = 9; board[2][4] = 0;
	board[3][0] = 0; board[3][1] = 10; board[3][2] = 0; board[3][3] = 0; board[3][4] = 9;
	board[4][0] = -3; board[4][1] = 1; board[4][2] = 15; board[4][3] = -4; board[4][4] = 2;

	EXPECT_EQ(38, Find_Max_Path(board, N));

	for (int i = 0; i < N; i++) {
		free(board[i]);
	}
	free(board);
}
