#include "Header.h"

extern long long** CreateMatrix(int const n, int const k);
extern void ZeroFill(long long* const arr, int const Size);
extern long long GetSum(long long* const arr, int const Size);
extern long long FindAmount(int const n, int const k, long long** HelperMatrix);

//TEST(HelloTest, BasicAssertions) {
//	// Expect two strings not to be equal.
//	EXPECT_STRNE("hello", "world");
//	// Expect equality.
//	EXPECT_EQ(7 * 6, 42);
//}

TEST(ZeroFillTest, DoesntFillEmptyArray)
{
	int Size = 0;
	long long* arr = NULL;
	long long* temp = arr;

	ZeroFill(arr, Size);

	EXPECT_EQ(arr, temp);
}

TEST(ZeroFillTest, FillsNonEmptyArrays)
{
	int Size = 1;
	long long* arr = (long long*)malloc(Size*sizeof(long long));
	long long* temp = (long long*)malloc(Size * sizeof(long long));
	for (size_t i = 0; i < Size; i++)
		temp[i] = arr[i];
	

	ZeroFill(arr, Size);

	for (size_t i = 0; i < Size; i++)
	{
		EXPECT_NE(arr[i], temp[i]);
	}
}

TEST(GetSumTest, ReturnsCorrectSum)
{
	const int Size1 = 5, Size2 = 6, Size3 = 10;
	long long arr1[Size1] = { 1,2,3,4,5 };
	long long arr2[Size2] = { 1,2,3,4,5,6 };
	long long arr3[Size3] = { 10,10,10,10,10,100,100,100,100,100 };

	long long Sum1 = GetSum(arr1,Size1);
	long long Sum2 = GetSum(arr2, Size2);
	long long Sum3 = GetSum(arr3, Size3);

	EXPECT_EQ(Sum1, 15);
	EXPECT_EQ(Sum2, 21);
	EXPECT_EQ(Sum3, 550);
}

TEST(GetSumTest, ReturnsZeroWhenEmptyArray)
{
	const int Size1 = 0;
	long long* arr1 = NULL;

	long long sum = GetSum(arr1, Size1);

	EXPECT_EQ(sum, 0);
}

TEST(CreateMatrixTest, CreatesMatrix)
{
	long long** matrix = NULL;
	int size1 = 1, size2 = 1;

	long long** CreatedMatrix = CreateMatrix(size1, size2);

	EXPECT_NE(matrix, CreatedMatrix);
}

TEST(CreateMatrixTest, FillsWithNegativeOnes)
{
	int const size1 = 1, size2 = 1;
	long long** matrix = CreateMatrix(size1, size2);

	for (size_t i = 0; i < size1 + 1; i++)
		for (size_t j = 0; j < size2 + 1; j++)
			EXPECT_EQ(matrix[i][j], -1);

}

TEST(CreateMatrixTest, ifKzeroReturnsNULL)
{
	int const k = 0, n = 1;
	long long** HelperMatrix = CreateMatrix(n,k);

	EXPECT_FALSE(HelperMatrix);
}

TEST(CreateMatrixTest, ifNzeroReturnsNULL)
{
	int const n = 0, k = 1;
	long long** HelperMatrix = CreateMatrix(n, k);

	EXPECT_FALSE(HelperMatrix);
}

TEST(FindAmountTest, ReturnsCorrectValue)
{
	int const n1 = 3, k1 = 2;
	int const n2 = 10, k2 = 90;
	int const n3 = 10, k3 = 15;
	
	long long** HelperMatrix1 = CreateMatrix(n1,k1);
	long long** HelperMatrix2 = CreateMatrix(n2, k2);
	long long** HelperMatrix3 = CreateMatrix(n3, k3);

	long long Amount1 = FindAmount(n1, k1, HelperMatrix1);
	long long Amount2 = FindAmount(n2, k2, HelperMatrix2);
	long long Amount3 = FindAmount(n3, k3, HelperMatrix3);
	//I'VE GOT ALL CORRECT ANSWERS USING BRUTE FORCE SOLUTION
	EXPECT_EQ(Amount1, 6);
	EXPECT_EQ(Amount2, 1);
	EXPECT_EQ(Amount3, 1287484);
}

TEST(FindAmountTest, ifKzeroReturnsOne)
{
	int const k = 0;
	int const n = 1;
	long long** HelperMatrix = NULL;

	long long Amount = FindAmount(n, k, HelperMatrix);

	EXPECT_EQ(Amount, 1);
}