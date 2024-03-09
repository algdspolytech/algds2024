#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

#include "dynamic_count.h"
#include "tests/trivial.h"
#include "tests/dynamic_count_tests.h"


void customTest() {
	int n, k;
	
	printf_s("Введите n и k через пробел: ");
	scanf_s("%i %i", &n, &k);
	printf_s("Хотите выполнить для сравнения алгоритм перебора (очень долгий)? (y/n): ");
	char answer = _getch();
	printf_s("\n");

	clock_t time;
	
	int countDyn = 0;
	double dynElapsedTime;

	printf_s("Выполняется вычисление...\n");
	time = clock();
	countDyn = countNumbers(n, k);
	dynElapsedTime = (double)(clock() - time) / CLOCKS_PER_SEC;

	printf_s("Результат: %i; время расчёта: %lf\n", countDyn, dynElapsedTime);

	if (answer == 'y') {
		int countEnum = 0;
		double enumElapsedTIme;

		printf_s("Выполняется вычисление перебором...\n");
		time = clock();
		countEnum = countNumberViaEnum(n, k);
		enumElapsedTIme = (double)(clock() - time) / CLOCKS_PER_SEC;

		printf_s("Перебор: результат: %i; время расчёта: %lf\n", countEnum, enumElapsedTIme);
	}
}


void printHelp() {
	printf_s(
		"1 - запустить юнит-тестирование\n"
		"2 - ввести свои n, k\n"
		"3 - выход\n> "
	);
}


void menu() {
	char answer;

	while (1) {
		printHelp();

		answer = _getch();
		printf_s("\n");

		switch (answer) {
		case '1':
			runAllTests();
			break;
		case '2':
			customTest();
			break;
		case '3':
			return;
			break;
		default:
			printf_s("Команды c таким кодом не существует");
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	menu();
	return 0;
}