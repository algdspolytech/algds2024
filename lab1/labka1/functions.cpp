#include "header.h"

int way_pay(int* num_array,int N, int from_i, int from_j) {

	if (N < 1 || from_i < 0 || from_j < 0 || (from_i > N - 1) || from_j>=SIZE) {
		return NULL;
	}

	if (N == 1) {
		return *(num_array + (from_i)*SIZE + from_j);
	}

	if (from_j == 0)
	{   
		return (int)fmax(way_pay(num_array, N-1, from_i - 1, from_j),
			way_pay(num_array, N-1, from_i - 1, from_j+1))+ *(num_array + (from_i)*SIZE + from_j);

	}
	else if (from_j == SIZE-1)
	{
		return (int)fmax(way_pay(num_array, N-1, from_i - 1, from_j),
			way_pay(num_array, N-1, from_i - 1, from_j -1)) + *(num_array + (from_i)*SIZE + from_j);
	}
    
	else 
	{
		return (int)fmax(fmax(way_pay(num_array, N-1,from_i - 1, from_j),
			way_pay(num_array, N-1 , from_i - 1, from_j - 1)),
			way_pay(num_array, N-1, from_i - 1, from_j + 1)) + *(num_array + (from_i)*SIZE + from_j);
	}
	
}
	
