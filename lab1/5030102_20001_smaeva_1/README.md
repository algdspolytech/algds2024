Лабораторная работа №1
Вариант 1
1 Задана матрица натуральных чисел A(n,m). За каждый проход через клетку (i,j) взимается штраф A(i,j). Необходимо минимизировать штраф и пройти из какой-либо клетки 1-ой строки в n-ую строчку, при этом из текущей клетки можно перейти в любую из 3-х соседних, стоящих в строке с номером на 1-цу большем



1. Установка g++ и  gtest
sudo apt-get install libgtest-dev libgmock-dev
sudo apt-get install google-mock
sudo apt-get install libtbb-dev
sudo apt-get install g++


2. Программа с массивом
2.1 Сборка для массива
g++ massiv_best_priority.c -o massiv_best_priority

2.2 Работа с массиовм
./massiv_best_priority 
Enter the number of rows: 2
Enter the number of columns: 3
Enter the elements of the matrix:
4
57
89
0
5
4
Minimum penalty to reach the last row: 4

3  Тестирование
3.1. Сборка для тестирования
g++ test_massiv_func.c massiv_best_priority_func.c -o test_mass -lgtest -pthread

3.2 Запуск тестов 
./test_mass 
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from MinPenaltyTest
[ RUN      ] MinPenaltyTest.PositiveNumbers
[       OK ] MinPenaltyTest.PositiveNumbers (0 ms)
[ RUN      ] MinPenaltyTest.NegativeNumbers
[       OK ] MinPenaltyTest.NegativeNumbers (0 ms)
[ RUN      ] MinPenaltyTest.ZeroMatrix
[       OK ] MinPenaltyTest.ZeroMatrix (0 ms)
[----------] 3 tests from MinPenaltyTest (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 3 tests.

