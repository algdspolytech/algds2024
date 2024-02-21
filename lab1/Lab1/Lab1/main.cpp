#include "Header.h"


extern int FindAmount(int const n, int const k);
extern void GetAmount();

int main(int argc, char* argv)
{
	//Interface -> n
	int n = 3;
	int k = 1;
	

	FindAmount(n, k);
	GetAmount();
}