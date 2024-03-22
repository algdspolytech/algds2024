#pragma once

int max(int a, int b) {
    if (a > b) {
        return (a);
    } else {
        return (b);
    }
}

int Result(int N, int A, int weights[], int values[]) {
    int F[N + 1][A + 1];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= A; j++) {
            F[i][j] = 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int y = 1; y <= A; y++) {
            if (weights[i - 1] <= y) {
                F[i][y] = max(F[i - 1][y], values[i - 1] + F[i - 1][y - weights[i - 1]]);
            } else {
                F[i][y] = F[i - 1][y];
            }
        }
    }
    // Check included elements
    int included[N + A];
    int i = N, y = A;
    while (i > 0 && y > 0) {
        if (F[i][y] != F[i - 1][y]) {
            included[i - 1] = 1;
            y -= weights[i - 1];
        } else {
            included[i - 1] = 0;
        }
        i--;
    }
    printf("Arr included elements:\n");
    for (int j = 0; j < N; j++) {
        if (included[j]) {
            printf("Element %d (weight %d, cost %d)\n", j + 1, weights[j], values[j]);
        }
    }
    return F[N][A];
}
