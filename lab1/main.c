#include <stdio.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"

int calculate_sequence(int *sequence, int size) {
    if (size == 0){
        printf("Sequence is empty\n");
        return -2;
    }
    int max = 0;
    int n = 1;
    int l = sequence[0];
    int k;
    for (int i = 1; i < size; i++) {
        k = sequence[i];
        if (k % l == 0){
            l = k;
            n++;
            max = (n > max)? n : max;
        }
        else{
            l = k;
            max = (n > max)? n : max;
            n = 1;
        }
    }
    return max;
}

int test_sequence1() {
    int sequence[] = {3, 5, 14, 3, 14, 3, 14, 2, 7, 2, 4, 7, 6, 12, 24, 48, 12, 2, 4, 1, 1, 1};
    int size = sizeof(sequence) / sizeof(sequence[0]);
    int wait_result = 4;
    int result = calculate_sequence(sequence, size);
    return result == wait_result;
}

int test_sequence2() {
    int sequence[] = {3, 5, 14, 3, 14, 3, 14, 2, 7, 2, 4, 7, 6, 12, 24};
    int size = sizeof(sequence) / sizeof(sequence[0]);
    int wait_result = 3;
    int result = calculate_sequence(sequence, size);
    return result == wait_result;
}

int test_sequence3() {
    int sequence[] = {6, 12, 24, 48, 12, 2, 4, 1, 1, 1, 3, 5, 14, 3, 14, 3, 14, 2, 7, 2, 4, 7};
    int size = sizeof(sequence) / sizeof(sequence[0]);
    int wait_result = 4;
    int result = calculate_sequence(sequence, size);
    return result == wait_result;
}

int main() {
    int test_results[3];
    test_results[0] = test_sequence1();
    test_results[1] = test_sequence2();
    test_results[2] = test_sequence3();
    for (int i = 0; i < 3; i++){
        if (test_results[i]){
            printf(GREEN "Test %d passed\n" RESET, i+1);
        }
        else{
            printf(RED "Test %d failed\n" RESET, i+1);
        }
    }
    return 0; 
}
