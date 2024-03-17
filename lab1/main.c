#define __STDC_WANT_LIB_EXT1__ 1
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <string.h>


void printString(char* A, int l){
    if(A == NULL) printf("Fatal Error: A is a null pointer!\n");
    if(l < 1) printf("Fatal Error: String has invalid length!\n");
    else{
    printf("String={");
    for(int i = 0; i<l;i++){
        printf("%c",A[i]);
    }
    printf("}\n");
    }
}

char* GenerateRandomString(char* A, int l){
    if(l<1){printf("Fatal Error: Invalid String Length (less than 1)\n"); return A;}

    char letters[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    A = (char*)malloc(l*sizeof(char));
    if(A==NULL) {printf("Fatal Error: Could not allocate memory!\n");return A;}
    for(int i = 0; i<l;i++){
        A[i]  = letters[rand()%26];
    }
    printString(A, l);
    return A;
}

int allocatedStringLength(char* A){
    if(A == NULL) {printf("Fatal Error: A is a null pointer!\n"); return 0;}
    int i = 0;
    do{
        i++;
    }while(A[i] <= 'Z' && A[i] >= 'A');
    return i;
}

int MinimumOfThree(int a, int b, int c){;
    return (a<b) ? (a<c?a:c) : (b<c?b:c);
}

int mAB(char A, char B){
    if(A == B) return 0;
    else return 1;
}



int d(char *A, char *B) { 
    if(A == NULL || B == NULL){printf("Fatal Error: A or B is a null pointer!\n"); return 0;}
    int m = allocatedStringLength(A), n = allocatedStringLength(B);
    if(m<n){
        m = m ^ n;
        n = n ^ m;
        m = m ^ n;
    }
    int p = 0, r = 0;
    int **d = (int **)malloc((m+1) * sizeof(int *));
    for (int i = 0; i <= m; i++){
        d[i] = (int *)malloc((m+1) * sizeof(int));
        d[i][0] = i;
    }
    for(int j = 0; j<= n; j++){
        d[0][j] = j;
    }   

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = MinimumOfThree(d[i-1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + mAB(A[i-1],B[j-1]));
        }
    }

    r = d[m][n];
    for (int i = 0; i <= m; i++) free(d[i]);
    free(d);

    return r;
}

void Testd_AequalsB_return0(){
    //arrange
    char* A = (char*)malloc(10*sizeof(char));
    char* B = (char*)malloc(10*sizeof(char));
    for(int i = 0; i<10;i++){
        A[i] = 'A';
        B[i] = A[i];
    }
    //act
    int c = d(A,B);
    
    //assert
    printf("Testd_AequalsB_return0(): %d\n",c);
}



void Testd_AandBset_return2(){
    //arrange
    char* A = (char*)malloc(10*sizeof(char));
    char* B = (char*)malloc(10*sizeof(char));
    for(int i = 0; i<10;i++){
        A[i] = 'A';
        B[i] = A[i];
    }
    B[2] = 'B';
    B[9] = 'B';
    //act
    int c = d(A,B);

    //assert
    printf("Testd_AandBset_return2(): %d\n",c);
}

void Testd_AandBset_return30(){
    //arrange
    char* A = (char*)malloc(100*sizeof(char));
    char* B = (char*)malloc(100*sizeof(char));
    for(int i = 0; i<10;i++){
        A[i] = 'A';
        B[i] = A[i];
    }
    for(int i = 0; i<30; i++){
        B[i] = 'B';
    }
    //act
    int c = d(A,B);

    //assert
    printf("Testd_AandBset_return30(): %d\n",c);
}

void Testd_BbiggerthanAby10_return10(){
    //arrange
    char* A = (char*)malloc(10*sizeof(char));
    char* B = (char*)malloc(20*sizeof(char));
    for(int i = 0; i<10;i++){
        A[i] = 'A';
        B[i] = A[i];
    }
    for(int i = 10; i<20; i++){
        B[i] = 'A';
    }
    //act
    int c = d(A,B);

    //assert
    printf("Testd_BbiggerthanAby10_return10(): %d\n",c);
}

void TestNegativeOfThree_ANegative10_ReturnNegative10(){
    //arrange
    int a = -10;
    int b = 1;
    int c = 3;
    //act
    int r = MinimumOfThree(a,b,c);
    //assert
    printf("TestNegativeOfThree_ANegative10_ReturnNegative10()): %d\n",r);
}

void main(void) {
	setlocale(LC_CTYPE, "Russian");
	system("chcp 1251");
    srand(time(NULL));
    char* A = NULL, *B = NULL;
    int a_length = 100;
    int b_length = 100;
    A = GenerateRandomString(A, a_length);
    B = GenerateRandomString(B, b_length);
    printf("Minimal Number of string Changes: %d\n",d(A,B));
    Testd_AequalsB_return0();
    Testd_AandBset_return2();
    Testd_BbiggerthanAby10_return10();
    Testd_AandBset_return30();
    TestNegativeOfThree_ANegative10_ReturnNegative10();
}