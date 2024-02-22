#include "Header.h"


extern long long FindAmount(int const n, int const k, long long** HelperMatrix);
extern FullMemo* InitFullMemo();
extern long long** CreateMatrix(int const n, int const k);
extern void ShowMatrix(long long** matr, int n, int k);

int main(int argc, char* argv)
{
	//Interface -> n
	int n = 1213;
	int k = 2;//4426837690959633216
			   
	long long** HelperMatrix = CreateMatrix(n, k);

	 // 1287484(10/15) ... 432457640(10/45)-3.28 opt - 7.00 notopt
	printf("%lld\n",FindAmount(n, k, HelperMatrix));
}