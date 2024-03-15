#include "math.h"
#include <limits.h>

typedef struct {
    float x;
    float y;
} Point;

float Distance(Point n1, Point n2) {
    float result = sqrt((n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y));
    return (result);
}

int Check(int i, int j, int N) {
    if (i == j) {
        return (0);
    } else if (i == j - 1) {
        return (0);
    } else if (i == j + 1) {
        return (0);
    } else if (j == 0 && i == N - 1) {
        return (0);
    } else if (j == N - 1 && i == 0) {
        return (0);
    }

    return (1);
}

void Result(int *pos_point, Point arr[], int N) {
    float min = INT_MAX;
    for (int j = 0; j < N; j++) {
        float max = 0;
        for (int i = 0; i < N; i++) {
            if (Check(i, j, N)) {
                float num = Distance(arr[j], arr[i]);
                if (num > max) {
                    max = num;
                }
            }
        }

        if (max < min) {
            min = max;
            *pos_point = j;
        }
    }
}