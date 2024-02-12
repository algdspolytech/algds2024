#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<string.h>
#include<lab1.h>

// Функция для вычисления минимума из трех чисел
int min(int a, int b, int c) {
    if (a < b) return (a < c) ? a : c;
    else return ( b < c ) ? b : c;
}

// Функция для вычисления расстояния d(x,y) используется алгоритм Levenshtein
int d(const char *x, const char *y) {
    int m = strlen(x);
    int n = strlen(y);    
    int i, j, cost, result;

    //Матрица (m+1)*(n+1)
    int **d = (int **)malloc((m+1) * sizeof(int *));
    for (i = 0; i <= m; i++)
        d[i] = (int *)malloc((n+1) * sizeof(int));

    for (i = 0; i <= m; i++) d[i][0] = i;
    for (j = 0; j <= n; j++) d[0][j] = j;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1])
                cost = 0;
            else cost = 1;
            d[i][j] = min(d[i - 1][j] + 1,         // Удаление
                           d[i][j - 1] + 1,         // Вставка
                           d[i - 1][j - 1] + cost); // Замена
                          
    
        }
    }

    result = d[m][n];
    for (i = 0; i <= m; i++) free(d[i]);
    free(d);

    return result;
}


int main(){
    char x[1000];
    char y[1000];
    printf("Enter x: ");
    fgets(x, sizeof(x), stdin);
    x[strcspn(x, "\n")] = 0;

    printf("Enter y: ");
    fgets(y, sizeof(y), stdin);
    y[strcspn(x, "\n")] = 0;

    printf("Number of conversion %s -> %s : %d", x, y, d(x,y));
    return 0;
}