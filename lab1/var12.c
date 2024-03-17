#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int min_cost(char* X, char* Y, int d, int i, int c) {
    int m = strlen(X);
    int n = strlen(Y);

    // Создаем таблицу для сохранения результатов подзадач
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int x = 0; x <= m; x++)
        dp[x] = (int*)malloc((n + 1) * sizeof(int));

    // Заполняем dp[][] в порядке снизу вверх
    for (int x = 0; x <= m; x++) {
        for (int y = 0; y <= n; y++) {

            // Если X пуст, то стоимость равна количеству символов в Y
            if (x == 0) {
                dp[x][y] = y * i;   // Min. operations = y

                // Если Y пуст, то стоимость равна количеству символов в X
            }
            else if (y == 0) {
                dp[x][y] = x * d;   // Min. operations = x

                // Если последние символы одинаковы, игнорируем последний символ
                // и рекурсивно вычисляем для оставшихся строк
            }
            else if (X[x - 1] == Y[y - 1]) {
                dp[x][y] = dp[x - 1][y - 1];

                // Если последний символ отличается, рассмотрим все три случая
            }
            else {
                dp[x][y] = MIN(MIN(dp[x][y - 1] + i,        // Вставка
                    dp[x - 1][y] + d),       // Удаление
                    dp[x - 1][y - 1] + c);     // Замена
            }
        }
    }

    int result = dp[m][n];

    // Освобождаем память
    for (int x = 0; x <= m; x++)
        free(dp[x]);
    free(dp);

    return result;
}

// char* input_word() {
//     char buffer[81]; // Буфер для ввода
//     scanf("%80s", buffer); // Читаем слово, но не более 80 символов

//     // Выделяем память ровно под размер введенного слова
//     char* word = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
//     strcpy(word, buffer); // Копируем слово из буфера в выделенную память

//     return word;
// }

// int read_int(const char* prompt) {
//     int value;
//     char ch;

//     while (1) {
//         printf("%s", prompt);
//         if (scanf("%d%c", &value, &ch) != 2 || ch != '\n') {
//             printf("Пожалуйста, введите число.\n");
//             while (getchar() != '\n'); // очистка буфера ввода
//         }
//         else {
//             break;
//         }
//     }

//     return value;
// }

// int main() {
//     //system("chcp 65001");

//     int choice;
//     char* X = NULL;
//     char* Y = NULL;
//     int d, i, e;

//     // Ввод исходных данных
//     printf("Введите исходное слово X: ");
//     X = input_word();
//     printf("Введите новое слово Y: ");
//     Y = input_word();
//     d = read_int("Введите стоимость удаления: ");
//     i = read_int("Введите стоимость вставки: ");
//     e = read_int("Введите стоимость замены: ");
//     printf("Минимальная стоимость = %d\n", min_cost(X, Y, d, i, e));

//     do {
//         printf("\n1. Заменить исходное слово X\n");
//         printf("2. Заменить новое слово Y\n");
//         printf("3. Изменить стоимости операций\n");
//         printf("4. Вычислить минимальную стоимость\n");
//         printf("0. Выход\n");
//         printf("Выберите действие: ");
//         scanf("%d", &choice);

//         switch (choice) {
//         case 1:
//             printf("Введите исходное слово X: ");
//             if (X != NULL) free(X); // Освобождаем память, если X уже был введен
//             X = input_word();
//             printf("Минимальная стоимость = %d\n", min_cost(X, Y, d, i, e));
//             break;
//         case 2:
//             printf("Введите новое слово Y: ");
//             if (Y != NULL) free(Y); // Освобождаем память, если Y уже был введен
//             Y = input_word();
//             printf("Минимальная стоимость = %d\n", min_cost(X, Y, d, i, e));
//             break;
//         case 3:
//             d = read_int("Введите стоимость удаления: ");
//             i = read_int("Введите стоимость вставки: ");
//             e = read_int("Введите стоимость замены: ");
//         case 4:
//             printf("Минимальная стоимость = %d\n", min_cost(X, Y, d, i, e));
//         default:
//             choice = 0;
//         }
//     } while (choice != 0);

//     // Освобождаем память
//     if (X != NULL) free(X);
//     if (Y != NULL) free(Y);

//     return 0;
// }



void test_min_cost() {
    char* X = "kitten";
    char* Y = "sitting";
    int d = 1; // стоимость удаления
    int i = 3; // стоимость вставки
    int e = 1; // стоимость замены

    assert(min_cost(X, Y, d, i, e) == 5);

    X = "flaw";
    Y = "lawn";
    assert(min_cost(X, Y, d, i, e) == 4);


    X = "";
    Y = "sitting";
    d = 1; // стоимость удаления
    i = 2; // стоимость вставки
    e = 1; // стоимость замены

    assert(min_cost(X, Y, d, i, e) == 14);

    X = "kitten";
    Y = "";
    d = 1; // стоимость удаления
    i = 2; // стоимость вставки
    e = 1; // стоимость замены

    assert(min_cost(X, Y, d, i, e) == 6);

    X = "cap";
    Y = "dad";
    d = 1; // стоимость удаления
    i = 2; // стоимость вставки
    e = 2; // стоимость замены

    assert(min_cost(X, Y, d, i, e) == 4);

}

int main() {
    test_min_cost();
    printf("All tests passed successfully.\n");
    return 0;
}
