#pragma once

int Count_number(int n, int k) {
    if (n == 0 & k != 0)
        return 0;
    if (k == 0)
        return 1;
    if (k > 9 * n)
        return 0;
    unsigned long long int count = 0;
    for (int i = 0; i <= 9; i++)
        if (k - i >= 0)
            count += Count_number(n - 1, k - i);
    return count;
}