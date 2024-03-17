#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int minDeletion(int arr[], int n) {
    // Создаем массив для хранения длин LIS
    int* lis = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        lis[i] = 1;

    // Создаем массив для хранения индексов предыдущих элементов в LIS
    int* prev = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        prev[i] = -1;

    // Находим LIS в массиве и заполняем массив prev
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Находим максимальное значение LIS
    int max = 0;
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (max < lis[i]) {
            max = lis[i];
            maxIndex = i;
        }
    }

    // Восстанавливаем LIS
    int* sequence = (int*)malloc(sizeof(int) * max);
    int k = max - 1;
    int i = maxIndex;
    while (i >= 0) {
        sequence[k] = arr[i];
        k--;
        i = prev[i];
    }

    // Выводим исходный массив
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Выводим полученную возрастающую последовательность
    printf("Increasing sequence after removal of elements: ");
    for (int i = 0; i < max; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    // Освобождаем память, выделенную под lis и prev
    free(lis);
    free(prev);
    free(sequence);

    // Количество элементов для удаления
    return n - max;
}

// Unit test функция
void test_minDeletion() {
    int arr1[] = { 5, 2, 8, 6, 3, 6, 9, 7 };
    int arr2[] = { 3, 10, 2, 1, 20 };
    int arr3[] = { 3, 2 };
    int arr4[] = { 50, 3, 10, 7, 40, 80 };

    int result1 = minDeletion(arr1, sizeof(arr1) / sizeof(arr1[0]));
    int result2 = minDeletion(arr2, sizeof(arr2) / sizeof(arr2[0]));
    int result3 = minDeletion(arr3, sizeof(arr3) / sizeof(arr3[0]));
    int result4 = minDeletion(arr4, sizeof(arr4) / sizeof(arr4[0]));

    printf("Test 1: Expected 3, Result %d\n", result1);
    printf("Test 2: Expected 2, Result %d\n", result2);
    printf("Test 3: Expected 0, Result %d\n", result3);
    printf("Test 4: Expected 3, Result %d\n", result4);
}

int main() {
    test_minDeletion();
    return 0;
}
