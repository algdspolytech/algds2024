#include "Header.h"


extern long long FindAmount(int const n, int const k, long long** HelperMatrix);
extern FullMemo* InitFullMemo();
extern long long** CreateMatrix(int const n, int const k);
extern void ShowMatrix(long long** matr, int n, int k);

int main(int argc, char* argv)
{

	int n, k;

	printf("Type in n and k parameters, please.\n");
	scanf("%d %d", &n, &k);
	
			   
	long long** HelperMatrix = CreateMatrix(n, k);


	printf("%lld\n",FindAmount(n, k, HelperMatrix));
}