#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
//#define _CRT_SECURE_NO_WARNINGS

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

//void PrintNumb(int n, int k) {
//
//	int raz = 1, maxi = pow(10, n) - 1;
//
//	for (int i = 1; i <= maxi; ++i) {
//		if (i % (int)pow(10, raz) == 0) {
//			raz += 1;
//		}
//		if (CountSum(i, k)) {
//			for (int j = 0; j < n - raz; ++j) {
//				printf("0");
//			}
//			printf("%d\n", i);
//		}
//	}
//}

void PrintNumber(double n, double k) {
	if ((floor(n) == n && (int)n == (char)n) && (floor(k) == k && (int)k == (char)k) && n > 0 && k > 0) {
		int raz = 1, maxi = pow(10, (int)n) - 1;

		for (int i = 1; i <= maxi; ++i) {
			if (i % (int)pow(10, raz) == 0) {
				raz += 1;
			}
			if (CountSum(i, (int)k)) {
				for (int j = 0; j < (int)n - raz; ++j) {
					printf("0");
				}
				printf("%d\n", i);
			}
		}
	}
	else {
		printf("Введите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");
	}
}

//int main() {
//	setlocale(LC_ALL, "Rus");
//	PrintNumber(3, 6);
//	PrintNumber(1.2, 4);
//	PrintNumber('hd', 'j');
//}

//int main() {
//	int n, k;
//	setlocale(LC_ALL, "Rus");
//
//	printf("Значность чисел и сумма: ");
//
//	while (1) {
//		if (scanf("%d %d", &n, &k) == 2 && n > 0 && k > 0) {
//			break;
//		}
//		else {
//			int c;
//			while ((c = getchar()) != '\n' && c != EOF);
//			printf("Введите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");
//		}
//	}
//	PrintNumb(n, k);
//}