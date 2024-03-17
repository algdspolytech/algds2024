#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main() {
    system("chcp 1251");

    int choice;
    char* X = NULL;
    char* Y = NULL;
    int d, i, e;

    // Пример 1: "алгоритм" в "аллигатор"
    X = _strdup("алгоритм");
    Y = _strdup("аллигатор");
    d = 2;
    i = 3;
    e = 1;
    printf(" \"%s\" -> \"%s\": %d\n", X, Y, min_cost(X, Y, d, i, e));

    // Пример 2: "аллигатор" в "коммутатор"
    X = _strdup("аллигатор");
    Y = _strdup("коммутатор");
    printf(" \"%s\" -> \"%s\": %d\n", X, Y, min_cost(X, Y, d, i, e));

    // Пример 3: "коммутатор" в "оператор"
    X = _strdup("коммутатор");
    Y = _strdup("оператор");
    printf(" \"%s\" -> \"%s\": %d\n", X, Y, min_cost(X, Y, d, i, e));

    // Пример 4: "кот" в "котенок"
    X = _strdup("кот");
    Y = _strdup("котенок");
    d = 2;
    i = 1;
    e = 2;
    printf(" \"%s\" -> \"%s\": %d\n", X, Y, min_cost(X, Y, d, i, e));

    // Пример 5: "мама" в "папа"
    X = _strdup("мама");
    Y = _strdup("папа");
    d = 2;
    i = 2;
    e = 1;
    printf(" \"%s\" -> \"%s\": %d\n", X, Y, min_cost(X, Y, d, i, e));

    // Пример 6: "дом" в "домик"
    X = _strdup("дом");
    Y = _strdup("домик");
    d = 3;
    i = 1;
    e = 2;
    printf(" \"%s\" -> \"%s\": %d\n", X, Y, min_cost(X, Y, d, i, e));
    return 0;
}