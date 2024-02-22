#pragma once
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