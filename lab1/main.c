#include "stdlib.h"
#include <stdio.h>
#include "main.h"

int main(void) {
    int N;
    printf("Enter num of points: ");
    scanf("%d", &N);
    Point *arr = (Point *) calloc(N, sizeof(Point));
    for (int j = 0; j < N; j++) {
        printf("Enter point: ");
        scanf("%f %f", &arr[j].x, &arr[j].y);
    }

    int pos_point = 0;

    Result(&pos_point, arr, N);

    printf("User: Point(%.2f, %.2f) - main point!\n", arr[pos_point].x, arr[pos_point].y);
    for (int j = 0; j < N; j++) {
        if (Check(pos_point, j, N)) {
            printf("Create diag with coordinates: (%.2f, %.2f), (%.2f, %.2f)\n", arr[pos_point].x, arr[pos_point].y,
                   arr[j].x, arr[j].y);
        }
    }
    return (0);
}