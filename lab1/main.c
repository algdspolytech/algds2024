#include <stdio.h>

#include "framework.h"
#include "test.h"

void main() {
	TEST(19, "tests_folder/test1.txt");
	TEST(0, "tests_folder/test2.txt");
	TEST(20, "tests_folder/test3.txt");
	TEST(0, "tests_folder/test4.txt");
	TEST(16, "tests_folder/test5.txt");
	//printf("total sum: %d", Finder(data));
}

/*
Задано число А и два вектора b[1..n] и c[1..n].
c[i] – стоимость i-го предмета, b[i] – его вес.

Предполагается, что 1<b[i]<=A.
Найти множество I, являющееся подмножеством множества {1,...,n}, такое, что SUM_i_b <= А, a SUM_i_c является максимальной.

Подсказка:
Обозначим через F[k,y] величину наибольшей суммарной стоимости элементов
с номерами не большими k, суммарный вес которых не превышает y.

7 5
2 4 2 3 2
1 2 3 4 5
*/