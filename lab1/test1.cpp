// Тесты на языке C++ с использованием gtest
#include <gtest/gtest.h>
#include "main.c" // Подключаем основной файл программы

// Тест 1
TEST(FindMaxCostTest, Test1) {
    int A1 = 10;
    int n1 = 3;
    int b1[] = {0, 2, 3, 4};  // Первый элемент игнорируется
    int c1[] = {0, 4, 5, 6};  // Первый элемент игнорируется
    int expected_result1 = 15;

    int result1 = findMaxCost(A1, n1, b1, c1);
    EXPECT_EQ(expected_result1, result1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
