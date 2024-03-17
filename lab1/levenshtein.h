#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H
#include <stdio.h>
#include <wchar.h>

int minimum(int a, int b, int c);
int levenshteinDistance(wchar_t* x, int m, wchar_t* y, int n);

#endif
