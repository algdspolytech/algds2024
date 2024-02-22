#include "Header.h"


extern int FindAmount(int const n, int const k, FullMemo* Memo);
extern void GetAmount();
extern FullMemo* InitFullMemo();

int main(int argc, char* argv)
{
	//Interface -> n
	int n = 10;
	int k = 90;
	FullMemo* Memo = InitFullMemo();
	FindAmount(n, k, Memo);
	GetAmount();
}