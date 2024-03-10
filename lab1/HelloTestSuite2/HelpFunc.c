#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "HelpFunc.h"

int FindCountMax(char name[20]) {
    FILE* ptr;
    int count = 1;
    int countMax = 1;
    char c;

    ptr = fopen(name, "r");


    if (ptr) {
        int numbers[50];
        int NumOfElm = 0;

        while (fscanf_s(ptr, "%d", &numbers[NumOfElm]) != EOF) {
            NumOfElm++; 
        }

        fclose(ptr);

        int integer = 0;
        while (integer + 1 < NumOfElm) {

            if ((numbers[integer] != 0) && (numbers[integer + 1] % numbers[integer] == 0)) {
                count++;
                if (count > countMax) countMax = count;

            }
            else {
                count = 1;
            }
            integer++;
        }

        if (NumOfElm == 0) countMax = 0;
    }

    else printf("File is not open\n");

   

    return countMax;
}

