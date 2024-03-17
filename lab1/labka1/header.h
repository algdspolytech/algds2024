#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <malloc.h>
#include <assert.h>
#define	SIZE 3


using namespace std;

void print_array(int* num_array, int N);
void fill_array(int* num_array, int N);

int way_pay(int* num_array,int N, int from_i, int from_j);
void Test_way_pay();