#include "dyn_prog.h"
//

#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>

int doubler(int a) {
	return a * 2;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int findSubset(int n, int A, int* p, int b[], int c[]) {
    if ((b[n] < 0) || (c[n] < 0)) {
        printf("ERRROR: UNCORRECT DATA!\n");
    }

    int** F = (int**)malloc((n + 1) * sizeof(int*));
        for (int i = 0; i < (n + 1); i++) {
            F[i] = (int*)malloc((A + 1) * sizeof(int));
        }

    for (int k = 0; k <= n; k++) {
        for (int y = 0; y <= A; y++) {
            if (k == 0 || y == 0) {
                F[k][y] = 0;
            }
            else if (b[k] > y) {
                F[k][y] = F[k - 1][y];
            }
            else {
                F[k][y] = max(F[k - 1][y], F[k - 1][y - b[k]] + c[k]);
            }
        }
    }

    int SUMi_b = 0;
    int max— = F[n][A];
    int maxCost = max—;

    int y = A;


    
    int i = 0;
    int ans = 0;
    for (int k = n; k > 0 && max— > 0; k--) {
        if (F[k][y] != F[k - 1][y]) {
            //printf(" %d ", k);
            ans = 10*ans + k;
            //printf(" %d ", ans);
            i++;
            y -= b[k];

            max— -= c[k];
            SUMi_b += b[k];
            (*p)++;
        }
    }

    /*char str[10];
    snprintf(str, sizeof str, "%d", ans);
    printf("Result: %s\n", str);        // Result: 354
    str[(*p)] = '\0';
    
    char* res = (char*)malloc(sizeof(str));
    res = str;
    printf("Result2: %s\n", res); */
    
    //printf("\nSubset I: { %d }\n", ans);

    int  res = 0, remainder;
    while (ans != 0) {
        remainder = ans % 10;
        res = res * 10 + remainder;
        ans /= 10;
    }
    printf("Res = %d\n", res);

    //printf("} (array starts with 1)\n");
    //printf("Max Cost: %d\n", maxCost);
    //printf("SUMi_b = %d\n", SUMi_b);
    return res;
}