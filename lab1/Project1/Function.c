#include "Header.h"

int FindNumber(int n, int sum, int k, int count) {
	if ((n + 1) * 9 < (k - sum)) return count;
	if (n == 0) {
		if (sum + 9 >= k) return (count + 1);
		else return count;
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (sum + i <= k) count = FindNumber(n - 1, sum + i, k, count);
		}
	}
	return count;
}

//
//  sum - собранная сумма
//  k - необходимая сумма
//  n - номер запуска или номер разряда
//  count - полученное количество
//

int CountNumbersWithSumK(int a, int b) {
	int count = 0;
	count = FindNumber(a - 1, 0, b, count);
	return count;
}