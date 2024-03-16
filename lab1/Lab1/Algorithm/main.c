#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

int main(void) {
    int n = 0;
    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &n);
    if (n < 3) {
        printf("There must be at least 3 points to form a triangle\n");
        return NUMBER_OF_POINTS_ERROR;
    }

    Point* points = (Point*)malloc(sizeof(Point) * n);
    if (!points) {
        printf("Memory allocation error");
        return MEMORY_ERROR;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter the coordinates of the point: ");
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double** table = Triangulation(points, n);
    printf("The minimum length of the longest diagonal in the triangulation is: %lf", table[0][n - 1]);

    for (int i = 0; i < n; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}