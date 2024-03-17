#include "header.h"

int main() {
	
	srand(time(NULL));
	Test_way_pay();

	int* array = (int*)malloc(SIZE * SIZE * sizeof(int));
	if (array == NULL) {
		printf("Error: Memory allocation failed.\n");
		return 1;
	}

	fill_array(array, SIZE);

	printf("\nCell values ​​on the board:\n");
	print_array(array, SIZE);

	int start_y;
	printf("\nEnter the initial y, it should be an integer from 0 to	SIZE - 1\n start_y = ");
	 scanf_s("%i", &start_y);

	int result = way_pay(array, SIZE, SIZE - 1, start_y);
	printf ("%d ", result);

	free(array);

	return 0;
}