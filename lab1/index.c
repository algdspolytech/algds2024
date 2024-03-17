#include <stdio.h>
#include <string.h>
#include "index.h"

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int editDistance(char* x, char* y) {
    int m = strlen(x);
    int n = strlen(y);
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
    char x[] = "ilove";
    char y[] = "russia";
    printf("Минимальное число операций для преобразования '%s' в '%s': %d\n", x, y, editDistance(x, y));
    return 0;
}