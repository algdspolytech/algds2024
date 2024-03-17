#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <malloc.h>

typedef struct
{
    float x;
    float y;
} Point;

float distanceBetweenTwoPoints(Point n1, Point n2)
{
    return sqrt(pow((n1.x - n2.x),2) + pow((n1.y - n2.y),2));
}

int isAValidDiagonal(int i, int j, int n) 
{
    if (n<4){printf("Количество точек меньше 4, алгоритм невозможно выполнить!\n");}
    else{
    if (i == j || abs(j - i) == 1 || abs(j - i) == n - 1)
    {
        return(1);
    }
    else{
    return(0);
    }
    }
}

int calculateResult(Point obj[], int n)
{

    if (n<4){printf("Количество точек меньше 4, алгоритм невозможно выполнить!\n");}
    else{
        int max_d = 0;
        float min = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            float max = 0;
            for (int i = 0; i < n; i++)
            {
                if (!isAValidDiagonal(i, j, n))
                {
                    float num = distanceBetweenTwoPoints(obj[j], obj[i]);
                    if (num > max)
                    {
                        max = num;
                    }
                }
            }

            if (max < min)
            {
                min = max;
                max_d = j;
            }
        }
        return max_d;
    }
  
}

Point* InputData(int* n){

    printf("The number of vertices for the polygon: ");
    scanf("%d", n);
    Point* obj = (Point*)malloc((*n)*sizeof(Point));
    for (int j = 0; j < (*n); j++)
    {
        printf("The coordinates of the points: ");
        scanf("%f %f", &obj[j].x, &obj[j].y);
    }
    return obj;
}

void OutputData (int n, int max_d, Point* obj){
    printf("(%.2f, %.2f): is the main vertex of the Polygon.\n", obj[max_d].x, obj[max_d].y);
    printf("Draw the diagonals, connecting the following point:\n");
    for (int j = 0; j < n; j++)
    {
        if (!isAValidDiagonal(max_d, j, n))
        {
            printf("(%.2f, %.2f)---->(%.2f, %.2f)\n", obj[max_d].x, obj[max_d].y, obj[j].x, obj[j].y);
        }
    }
}


void TestDistanceBetweenTwoPoints_ZeroZeroAndZeroTwo_ResultTwo(){
    //arrange
    Point p1={0,0}, p2={2,0};
    //act
    float d = distanceBetweenTwoPoints(p1,p2);
    //assert
    printf("TestDistanceBetweenTwoPoints_ZeroZeroAndZeroTwo_ResultTwo(): %lf\n",d);
}

void TestDistanceBetweenTwoPoints_TwoPoints_ResultFive(){
    //arrange
    Point p1={2,-2}, p2={5,2};
    //act
    float d = distanceBetweenTwoPoints(p1,p2);
    //assert
    printf("TestDistanceBetweenTwoPoints_TwoPoints_ResultFive() %lf\n",d);
}

void TestIsAValidDiagonal_FixedInput_ReturnOne(){
    //arrange
    int n = 6, j = 0, i = n-1;
    //act
    float r = isAValidDiagonal(i,j,n);
    //assert
    printf("TestIsAValidDiagonal_FixedInput_ReturnOne(): %lf\n",r);
}

void TestIsAValidDiagonal_FixedInput_ReturnZero(){
    //arrange
    int n = 25, j = 20, i = 5;
    //act
    float r = isAValidDiagonal(i,j,n);
    //assert
    printf("TestIsAValidDiagonal_FixedInput_ReturnZero(): %lf\n",r);
}

void TestCalculateResult_FixedInput_ReturnZero(){
    //arrange
    int m_d;
    const int n = 5;
    Point obj[5] = {{0, 0}, {1, 2}, {3, 1}, {2, -1}, {0.5, -2}};
    //act
    float r = calculateResult(obj,n);
    //assert
    printf("TestCalculateResult_FixedInput_ReturnZero(): %lf\n",r);
}

void TestCalculateResult_FixedInput_ReturnOne(){
    //arrange
    int m_d;
    const int n = 6;
    Point obj[6] = {{0, 0}, {0, 2}, {1, 4}, {2, 4}, {4, 3}, {4, 1}};
    //act
    float r = calculateResult(obj,n);
    //assert
    printf("TestCalculateResult_FixedInput_ReturnOne(): %lf\n",r);
}

int main()
{
    int n;
    Point* obj = InputData(&n);
    int max_d = calculateResult(obj, n);
    OutputData(n, max_d, obj);
    TestDistanceBetweenTwoPoints_ZeroZeroAndZeroTwo_ResultTwo();
    TestDistanceBetweenTwoPoints_TwoPoints_ResultFive();
    TestIsAValidDiagonal_FixedInput_ReturnOne();
    TestIsAValidDiagonal_FixedInput_ReturnZero();
    TestCalculateResult_FixedInput_ReturnZero();
    TestCalculateResult_FixedInput_ReturnOne();
    return(0);
}
