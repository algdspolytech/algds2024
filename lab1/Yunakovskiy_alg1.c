#define STDC_WANT_LIB_EXT1 1
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#define N 10

void printStr(char* A, int length)
{
    if (A == NULL) printf("Err: A is a null pointer!\n");
    
    if (length < 1) printf("Err: String has invalid length!\n");
    else
    {
        printf("String = {");
        for(int i = 0; i < length; i++)
        {
            printf("%c",A[i]);
        }
        printf("}\n");
    }
}

char* RandStr(char* A, int length)
{
    if (length < 1) 
    {
        printf("Err: Invalid String Length\n"); 
        return A;
        
    }
    char letter[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    A = (char*)malloc(length*sizeof(char));
    if (A == NULL) 
    {
        printf("Err: Couldn't allocate memory!\n");
        return A;
    }
    for(int i = 0; i < length; i++)
    {
        A[i]  = letter[rand()%26];
    }
    printStr(A, length);
    return A;
}

int allocStrLength(char* A)
{
    if (A == NULL) 
    {
        printf("Err: A is a null pointer!\n"); 
        return 0;
    }
    int i = 0;
    do
    {
        i++;
    }
    while (A[i] <= 'Z' && A[i] >= 'A');
    return i;
}

int Min_3(int a, int b, int c)
{
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int A_B(char A, char B)
{
    if (A == B) return 0;
    else return 1;
}

int d(char *A, char *B) 
{ 
    if (A == NULL || B == NULL)
    {
        printf("Err: A or B is a null pointer!\n"); 
        return 0;
        
    }
    
    int m = allocStrLength(A), n = allocStrLength(B);
    
    if (m < n)
    {
        m = m ^ n;
        n = n ^ m;
        m = m ^ n;
    }
    
    int p = 0, res = 0;
    int **d = (int **)malloc((m+1) * sizeof(int *));
    
    for (int i = 0; i <= m; i++)
    {
        d[i] = (int *)malloc((m+1) * sizeof(int));
        d[i][0] = i;
    }
    for(int j = 0; j<= n; j++)
    {
        d[0][j] = j;
    }   

    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            d[i][j] = Min_3(d[i-1][j] + 1,                              // delete
                            d[i][j - 1] + 1,                            // insert
                             d[i - 1][j - 1] + A_B(A[i-1],B[j-1]));     // substitute
        }
    }

    res = d[m][n];
    for (int i = 0; i <= m; i++) free(d[i]);
    free(d);

    return res;
}

void Test_AequalsB()
{
    // Arrange (A1)
    char* A = (char*)malloc(N * sizeof(char));
    char* B = (char*)malloc(N * sizeof(char));
    for(int i = 0; i < N; i++)
    {
        A[i] = 'A';
        B[i] = A[i];
    }
    
    // Act (A2)
    int c = d(A,B);
    
    // Assert (A3)
    printf("Testd_AequalsB(): %d\n",c);
}



void Test_AandBset_2()
{
    // A1
    char* A = (char*)malloc(N * sizeof(char));
    char* B = (char*)malloc(N * sizeof(char));
    for(int i = 0; i < N; i++)
    {
        A[i] = 'A';
        B[i] = A[i];
    }
    B[2] = 'B';
    B[9] = 'B';
    
    // A2
    int c = d(A,B);

    // A3
    printf("Testd_AandBset_2(): %d\n",c);
}

void Test_AandBset_30()
{
    // A1
    char* A = (char*)malloc((N * N) * sizeof(char));
    char* B = (char*)malloc((N * N) * sizeof(char));
    for(int i = 0; i < N; i++)
    {
        A[i] = 'A';
        B[i] = A[i];
    }
    for(int i = 0; i < 30; i++){
        B[i] = 'B';
    }
    
    // A2
    int c = d(A,B);

    // A3
    printf("Testd_AandBset_30(): %d\n",c);
}

void Test_BbiggerthanA()
{
    // A1
    char* A = (char*)malloc(N * sizeof(char));
    char* B = (char*)malloc(20 * sizeof(char));
    for (int i = 0; i < N; i++)
    {
        A[i] = 'A';
        B[i] = A[i];
    }
    for (int i = N; i < 20; i++)
    {
        B[i] = 'A';
    }
    
    // A2
    int c = d(A,B);

    // A3
    printf("Testd_BbiggerthanA(): %d\n",c);
}

void Test_Negative()
{
    // A1
    int a = -2;
    int b = 7;
    int c = 9;
    
    // A2
    int r = Min_3(a, b, c);
    
    // A3
    printf("Test_Negative()): %d\n",r);
}
void main(void) {
    setlocale(LC_CTYPE, "Russian");
    system("chcp 1251");
    srand(time(NULL));
    char* A = NULL, *B = NULL;
    int a_length = 100;
    int b_length = 100;
    A = RandStr(A, a_length);
    B = RandStr(B, b_length);
    printf("Minimal Number of string Changes: %d\n",d(A,B));
    Test_AequalsB();
    Test_AandBset_2();
    Test_BbiggerthanA();
    Test_AandBset_30();
    Test_Negative();
}
