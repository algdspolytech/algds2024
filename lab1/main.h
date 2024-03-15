#pragma once
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

float dist(Point n1, Point n2) {
    float result = sqrt((n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y));
    return (result);
}

int proverka(int i, int j, int n) {
    if (i == j) {
        return (1);
    } else if (abs(j - i) == 1) {
        return (1);
    } else if (abs(j - i) == n - 1) {
        return (1);
    }

    return (0);
}

void finish(int *m_d, Point obj[], int n) {
    float min = INT_MAX;
    for (int j = 0; j < n; j++) {
        float max = 0;
        for (int i = 0; i < n; i++) {
            if (!proverka(i, j, n)) {
                float num = dist(obj[j], obj[i]);
                if (num > max) {
                    max = num;
                }
            }
        }

        if (max < min) {
            min = max;
            *m_d = j;
        }
    }
}