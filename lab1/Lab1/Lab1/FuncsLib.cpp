#include "Header.h"

int IsInMemo(int const n, int const remainder, memo const Memo)
{
	if (Memo.n == n && Memo.remainder == remainder)
		return 1;
	else
		return 0;
}

FullMemo* InitFullMemo()
{
	FullMemo* NewMemo = (FullMemo*)malloc(sizeof(FullMemo));
	NewMemo->MemoArray = (memo*)malloc(sizeof(memo));
	NewMemo->MemoSize = 0;
	return NewMemo;
}

memo* Finder(int const n, int const remainder, FullMemo* const Memo)
{
	for (size_t i = 0; i < Memo->MemoSize; i++)
	{
		if (IsInMemo(n, remainder, Memo->MemoArray[i]))
			return &(Memo->MemoArray[i]);
		else
			return NULL;
	}
}

void AddToMemo(int const n, int const remainder, int const Amount, FullMemo* Memo)
{
	Memo->MemoArray = (memo*)realloc(Memo->MemoArray, (Memo->MemoSize + 1)*sizeof(memo));
	Memo->MemoSize++;
	Memo->MemoArray[Memo->MemoSize - 1].Amount = Amount;
	Memo->MemoArray[Memo->MemoSize - 1].remainder = remainder;
	Memo->MemoArray[Memo->MemoSize - 1].n = n;
}

int Amount = 0;

int FindAmount(int const n, int const k, FullMemo* Memo)
{
	memo* FoundedMemo = Finder(n,k,Memo);
	if (FoundedMemo)
	{
		Amount += FoundedMemo->Amount;
		return Amount;
	}
	if (k == 0)
	{
		return ++Amount;
	}
	else if (k < 0)
		return 0;
	else if (k > 0 && n == 0)
		return 0;

	
	for (size_t num = 0; num < 10; num++)
	{
		int remainder = k - num;
		if (remainder > 9 * n)
		{
			AddToMemo(n, remainder, 0, Memo);
			continue;
		}
		int temp = Amount;
		FindAmount(n - 1, remainder, Memo);
		if (temp != Amount)
				AddToMemo(n,remainder,Amount,Memo);
	}
}

void GetAmount()
{
	printf("%d", Amount);
}