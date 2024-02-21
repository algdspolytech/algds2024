#include "Header.h"


int Amount = 0;

int FindAmount(int const n, int const k)
{
	
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
		FindAmount(n - 1, remainder);
	}
}

void GetAmount()
{
	printf("%d", Amount);
}