#include "levenshtein.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int minimum(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b < a && b <= c) return b;
    else return c;
}


int levenshteinDistance(wchar_t* x, int m, wchar_t* y, int n) {
    // Äèíàìè÷åñêîå âûäåëåíèå ïàìÿòè äëÿ äâóìåðíîãî ìàññèâà
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + minimum(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        }
    }
    int result = dp[m][n];
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}


int main() {
    setlocale(LC_CTYPE, "");

    wchar_t x[] = L"ðtslddf";
    int m = wcslen(x);
    wchar_t y[] = L"tsgldds";
    int n = wcslen(y);

    int result = levenshteinDistance(x, m, y, n);
    wprintf(L"Ðàññòîÿíèå Ëåâåíøòåéíà ìåæäó ñòðîêàìè x è y: %d\n", result);

    return 0;
}
