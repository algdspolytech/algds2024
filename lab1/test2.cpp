// Тесты на языке C++ с использованием gtest
#include <gtest/gtest.h>
#include "main.c" // Подключаем основной файл программы

// Тест 2
TEST(FindMaxCostTest, Test2) {
    int A2 = 6;
    int n2 = 2;
    int b2[] = {0, 3, 2};  
    int c2[] = {0, 8, 5};  
    int expected_result2 = 13;

    int result2 = findMaxCost(A2, n2, b2, c2);
    EXPECT_EQ(expected_result2, result2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
