#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Thing {
	int weight;
	int cost;
} Thing;

typedef struct Data {
	int a;
	int size;
	Thing* t;
} Data;

FILE* OpenFile(char* name, char* mode);
void CloseFile(FILE* file);

int Finder(Data data);
int MaxSum(const Thing* f, const int size, const int sum_before);
void Init(const FILE* file, Data* data);
