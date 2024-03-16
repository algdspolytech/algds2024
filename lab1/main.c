#include <stdio.h>
#include <stdlib.h>
#include "find_max_incresing_subsequence.h"
// Функция для нахождения максимальной возрастающей подпоследовательности


int main() {
    int sequence[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int sequence_length = sizeof(sequence) / sizeof(sequence[0]);
    int length_of_subsequence;
    int *max_increasing_subsequence = find_max_increasing_subsequence(sequence, sequence_length, &length_of_subsequence);

    printf("Максимальная возрастающая подпоследовательность: ");
    for (int i =   0; i < length_of_subsequence ; i++)
        printf("%d ", max_increasing_subsequence[i]);
    printf("\n");

    // Освобождаем память, выделенную для max_increasing_subsequence
    free(max_increasing_subsequence);

    return 0;
}
