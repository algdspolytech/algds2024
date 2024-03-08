#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdlib.h> 
#include <stdio.h>


int* getarray(int n); 
void findans(int n, int A, const int** mas, const int* b,int* ans);
int** creatematrix( const int* b, const int* c, const int A,const int n);