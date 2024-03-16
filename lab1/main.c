#include <stdio.h>
#include <stdlib.h>

// Функция для нахождения максимальной возрастающей подпоследовательности
int* find_max_increasing_subsequence(int sequence[], int sequence_length, int *length_of_subsequence) {
    // Выделяем память для массива длин increasing_sequence_lengths
    int *increasing_sequence_lengths = (int*)malloc(sizeof(int) * sequence_length);
    // Инициализируем массив длин increasing_sequence_lengths
    for (int i = 0; i < sequence_length; i++)
        increasing_sequence_lengths[i] = 1;

    // Поиск длин increasing_sequence_lengths для каждого элемента
    for (int i = 1; i < sequence_length; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[i] > sequence[j] && increasing_sequence_lengths[i] < increasing_sequence_lengths[j] + 1)
                increasing_sequence_lengths[i] = increasing_sequence_lengths[j] + 1;
        }
    }

    // Находим максимальную длину возрастающей подпоследовательности
    *length_of_subsequence = 0;
    for (int i = 0; i < sequence_length; i++) {
        if (increasing_sequence_lengths[i] > *length_of_subsequence)
            *length_of_subsequence = increasing_sequence_lengths[i];
    }

    // Выделяем память для массива subsequence
    int *subsequence = (int*)malloc(sizeof(int) * (*length_of_subsequence));

    // Восстанавливаем подпоследовательность, начиная с последнего элемента
    int current_length = *length_of_subsequence;
    int max_index = 0;
    for (int i = sequence_length - 1; i >= 0; i--) {
        if (increasing_sequence_lengths[i] == current_length && (max_index == 0 || sequence[i] < subsequence[max_index - 1])) {
            subsequence[max_index++] = sequence[i];
            current_length--;
        }
    }

    // Освобождаем память, выделенную для increasing_sequence_lengths
    free(increasing_sequence_lengths);

    // Возвращаем подпоследовательность
    return subsequence;
}

int main() {
    int sequence[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int sequence_length = sizeof(sequence) / sizeof(sequence[0]);
    int length_of_subsequence;
    int *max_increasing_subsequence = find_max_increasing_subsequence(sequence, sequence_length, &length_of_subsequence);

    printf("Максимальная возрастающая подпоследовательность: ");
    for (int i = length_of_subsequence - 1; i >= 0; i--)
        printf("%d ", max_increasing_subsequence[i]);
    printf("\n");

    // Освобождаем память, выделенную для max_increasing_subsequence
    free(max_increasing_subsequence);

    return 0;
}
