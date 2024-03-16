#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

void ScanCoef(int* d, int* i, int* c);
void DeleteSym(char* stringX, int i);
void InputSym(char* stringX, int i, char* sym);
void FindSol(char* stringX, char* stringY, int del, int inp, int change);
