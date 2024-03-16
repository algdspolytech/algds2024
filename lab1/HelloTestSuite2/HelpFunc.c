#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "HelpFunc.h"


int FindCountMax(int *numbers, int array_length) {
	int count = 1;
	int countMax = 1;
	
	int integer = 0;

	while (integer + 1 <array_length) {
		if ((numbers[integer] != 0) && (numbers[integer + 1] % numbers[integer] == 0)) {
			count++;
			if (count > countMax) countMax = count;

		}
		else {
			count = 1;
		}
		integer++;
	}

	if (array_length == 0) countMax = 0;
	

	return countMax;
}

