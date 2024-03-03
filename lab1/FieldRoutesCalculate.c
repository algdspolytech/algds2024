#include "FieldRoutesCalculate.h"

int calculateRoutesToEnd(int fieldSize, int maxStepLength) {
	/* -1 stands for an error during the function execution */

	int i, stepLength, result;
	int* field;

	if (fieldSize <= 0 || maxStepLength < 0) {
		return -1;
	}

	field = malloc((fieldSize + 1) * sizeof(int));
	if (field == NULL) {
		return -1;
	}
	field[0] = 1;
	for (int i = 1; i <= fieldSize; i++) {
		field[i] = 0;
	}

	for (i = 0; i <= fieldSize; i++) {
		for (stepLength = 1; stepLength <= maxStepLength && stepLength + i <= fieldSize; stepLength++) {
			field[i + stepLength] += field[i];
		}
	}

	result = field[fieldSize];
	free(field);

	return result;
}