#include <stdio.h>
#include <stdlib.h>
#include "lab1.h"

int countPaths(int n, int k) {

    if (n == 0 && k == 0) return 0;

    int* dp = (int*)malloc((n + 1) * sizeof(int));

    if (dp == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = 0;

        for (int j = 1; j <= k && i - j >= 0; j++) {
            dp[i] += dp[i - j];
        }
    }

    int result = dp[n];

    free(dp);

    return result;
}