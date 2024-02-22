#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

struct
{
	int n, remainder;
	int Amount;
} typedef memo;

struct
{
	int MemoSize;
	memo* MemoArray;
} typedef FullMemo;