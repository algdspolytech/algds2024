#include <gtest/gtest.h>

extern "C" {
#include "lab_03_01_v1.h"
}


// Тест для функции 
TEST(MaxSubsequenceLengthTest, BasicTest) {
    int arr1[] = { 3, 6, 9, 12, 15, 18, 21 }; // Ожидается результат 4
    int arr2[] = { 2, 4, 6, 8, 10 };          // Ожидается результат 5
    int arr3[] = { 5, 10, 15, 20, 25 };       // Ожидается результат 2

    EXPECT_EQ(maxSubsequenceLength(arr1, 7), 4);
    EXPECT_EQ(maxSubsequenceLength(arr2, 5), 5);
    EXPECT_EQ(maxSubsequenceLength(arr3, 5), 2);
}

// Тест для функции с пустым массивом
TEST(MaxSubsequenceLengthTest, EmptyArrayTest) {
    EXPECT_EQ(maxSubsequenceLength(nullptr, 0), 1);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest();
    RUN_ALL_TESTS();

    return 0;
}
