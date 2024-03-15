#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int CountSum(int num, int k) {
	int sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
		if (sum > k) {
			return 0;
		}
	}
	return sum == k;
}

int PrintNumber(int n, int k) {
	int raz = 1, maxi = (int)pow(10, n) - 1;
	int countnumber = 0;
	for (int i = 1; i <= maxi; ++i) {
		if (i % (int)pow(10, raz) == 0) {
			raz += 1;
		}
		if (CountSum(i, k)) {
			countnumber += 1;
			for (int j = 0; j < n - raz; ++j) {
				printf("0");
			}
			printf("%d ", i);
		}
	}
	return countnumber;
}

int ReadNumber(double n, double k) {
	setlocale(LC_ALL, "Rus");
	if ((floor(n) == n && (int)n == (char)n) && (floor(k) == k && (int)k == (char)k) && n > 0 && k > 0) {
		PrintNumber(n, k);
	}
	else {
		printf("Введите корректные данные: <значность сумма> (целые положительные числа большие 0)\n");
		return 0;
	}
}

//int main() {
//	ReadNumber(3, 6);
//	ReadNumber(1.2, 4);
//	ReadNumber('hd', 'j');
//}