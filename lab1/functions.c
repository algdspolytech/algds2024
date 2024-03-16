#include "lab_03_01_v1.h"

int maxSubsequenceLength(int arr[], int n) {
    int* dp = (int*)malloc(n * sizeof(int));
    int maxLen = 1;

    for (int i = 0; i < n; i++)
        dp[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                if (maxLen < dp[i])
                    maxLen = dp[i];
            }
        }
    }

    free(dp);
    return maxLen;
}

