#include "pch.h"

#include "Header.h"



TEST(GetArray, NullTest) {
	int* b = getarray(0);
	EXPECT_EQ((int)b, NULL);
	EXPECT_TRUE(true);
}

TEST( NullTest, Creatematrix_tests) {
	int b [2] = {1,2};
	int c [2] = {2,1};
	int** mas = creatematrix((const int*)&b[0], (const int*)&c[0], 3, 0);
	EXPECT_EQ((int)mas, 0);
	EXPECT_TRUE(true);
}
TEST(Testcase_1, Algo_case_Creatematrix) {
	int b[2] = { 1,2 };
	int c[2] = { 2,1 };
	int** mas = creatematrix(&b[0], &c[0], 2, 2);
	EXPECT_EQ(mas[2][2], 2);
	EXPECT_TRUE(true);
}
TEST(Big_weight, Algo_case_Creatematrix_tests) {
	int b[2] = { 1,2 };
	int c[2] = { 2,1 };
	int** mas = creatematrix(&b[0], &c[0], 3, 2);
	EXPECT_EQ(mas[2][3], 3);
	EXPECT_TRUE(true);
}
TEST(Small_weight, Algo_case_Creatematrix_tests) {
	int b[2] = { 3 , 4 };
	int c[2] = { 2,1 };
	int** mas = creatematrix(&b[0], &c[0], 2, 2);
	EXPECT_EQ(mas[2][2], 0);
	EXPECT_TRUE(true);
}
TEST(Easy_Test, Findans_tests) {
	int b[5] = { 3,4 };
	int c[5] = { 1,6 };
	int** mas = creatematrix(&b[0], &c[0], 3, 2);
	int ans[2] = {};
	findans(2,3,(const int**)mas, &b[0], &ans[0]);
	EXPECT_EQ(ans[1], 0);
	EXPECT_EQ(ans[0], 1);
	EXPECT_TRUE(true);
}
TEST(Big_Wight_Test, Algo_Findans_tests) {
	int b[5] = { 1,2 };
	int c[5] = { 1,6 };
	int** mas = creatematrix(&b[0], &c[0], 3, 2);
	int ans[2] = {};
	findans(2, 3, (const int**)mas, &b[0], &ans[0]);
	EXPECT_EQ(ans[0], 1);
	EXPECT_EQ(ans[1], 2);
	EXPECT_TRUE(true);
}
TEST(Small_Wight_Test, Algo_Findans_tests) {
	int b[5] = { 3,4 };
	int c[5] = { 1,6 };
	int** mas = creatematrix(&b[0], &c[0], 2, 2);
	int ans[2] = {0};
	findans(2, 2, (const int**)mas, &b[0], &ans[0]);
	EXPECT_EQ(ans[0], 0);
	EXPECT_EQ(ans[1], 0);
	EXPECT_TRUE(true);
}
TEST(Small_amount_Test, Algo_Findans_tests) {
	int b[1] = { 3 };
	int c[1] = { 1 };
	int** mas = creatematrix(&b[0], &c[0], 4, 1);
	int ans[2] = { 0 };
	findans(1, 4, (const int**)mas, &b[0], &ans[0]);
	EXPECT_EQ(ans[0], 1);
	EXPECT_TRUE(true);
}