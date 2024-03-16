//
// Created by Никита Швачко on 16.03.2024.
//

#ifndef LAB1_FIND_MAX_INCRESING_SUBSEQUENCE_H
#define LAB1_FIND_MAX_INCRESING_SUBSEQUENCE_H

#include <stdlib.h>

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
    //разворачиваем подпоследовательность
    for (int i = 0; i < max_index / 2; i++){
        int temp = subsequence[i];
        subsequence[i] = subsequence[max_index - i - 1];
        subsequence[max_index - i - 1] = temp;

    }

    // Возвращаем подпоследовательность
    return subsequence;
}
#endif //LAB1_FIND_MAX_INCRESING_SUBSEQUENCE_H
