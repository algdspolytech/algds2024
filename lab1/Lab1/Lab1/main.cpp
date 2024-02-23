#include "Header.h"

extern long long FindAmount(int const n, int const k, long long** HelperMatrix);
extern long long** CreateMatrix(int const n, int const k);
//extern void ShowMatrix(long long** matr, int n, int k);

int main(int argc, char* argv[])
{

	int n = 3, k = 2;

	printf("Type in n and k parameters, please.\n");
	scanf("%d %d", &n, &k);
	
			   
	long long** HelperMatrix = CreateMatrix(n, k);


	printf("%lld\n",FindAmount(n, k, HelperMatrix));

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}