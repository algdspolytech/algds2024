#include "header.h"


void fill_array(int *num_array, int N) {

    if (num_array == NULL) {
        printf("Error: Null pointer passed to fill_array.\n");
        return;
    }

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			*(num_array+i*N+j) = rand()%201-100;
		}
	}
}

void print_array(int* num_array, int N) {

    if (num_array == NULL) {
        printf("Error: Null pointer passed to print_array.\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", *(num_array + i * N + j));
        }
        printf("\n");
    }
}
