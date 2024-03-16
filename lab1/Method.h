#pragma once

int Amount(int n, int k) {
    int res = 0;
    if (k == 0) {
        return 1;
    }
    if ((n == 0 && k != 0) || (k > 9 * n)) {
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (k - i >= 0) {
            res += Amount(n - 1, k - i);
        }
    }
    return res;
}