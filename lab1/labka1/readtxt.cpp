#include "header.h"


void read_txt(char name_txt[]) {
    int numberArray[4][4];


    FILE* myFile;
    if (fopen_s(&myFile, name_txt, "r") == 0) {
        printf("Error!\n");
    }

    if (myFile == NULL) {
        printf("Error!\n");

    }
    else {
        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 4; j++) {
                {
                    fscanf_s(myFile, "%d", &numberArray[i][j]);
                }
            }

        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++) {
            {
                printf_s("Number is: %d\n\n", numberArray[i]);
            }
        }
    }
    fclose(myFile);
}