#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <malloc.h>
#include <locale.h>
#include "main.h"

//{{0, 0}, {0, 2}, {1, 4}, {2, 4}, {4, 3}, {4, 1}} - шестиугольник
int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &n);
    Point *obj = (Point *) calloc(n, sizeof(Point));
    for (int j = 0; j < n; j++) {
        printf("Enter the coordinates of the point: ");
        scanf("%f %f", &obj[j].x, &obj[j].y);
    }

    int m_d = 0; //

    finish(&m_d, obj, n);

    printf("(%.2f, %.2f) - the desired vertex of the n-gon!\n", obj[m_d].x, obj[m_d].y);
    for (int j = 0; j < n; j++) {
        if (!proverka(m_d, j, n)) {
            printf("Draw the diagonals by connecting the dots: (%.2f, %.2f), (%.2f, %.2f)\n", obj[m_d].x, obj[m_d].y,
                   obj[j].x, obj[j].y);
        }
    }
    return (0);
}