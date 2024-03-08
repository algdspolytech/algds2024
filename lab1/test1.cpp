#include <gtest/gtest.h>
#include <string.h>
#include <stdlib.h>

extern "C" {
    #include "findLCS.h" // Предполагается, что ваш findLCS.h содержит объявления функций findLCS и max
}

// Тесты для функции findLCS
TEST(LCSTest, BasicTest) {
    char X[] = "10101";
    char Y[] = "10011";
    int m = strlen(X);
    int n = strlen(Y);
    char* result = findLCS(X, Y, m, n);
    ASSERT_STREQ(result, "1001");
    free(result); // Очистка памяти после каждого тест1а
}

TEST(LCSTest, TestEmptyString) {
    char X[] = "";
    char Y[] = "10011";
    int m = strlen(X);
    int n = strlen(Y);
    char* result = findLCS(X, Y, m, n);
    ASSERT_STREQ(result, "");
    free(result);
}

// Тесты для функции max
TEST(MaxTest, HandlesPositiveNumbers) {
    EXPECT_EQ(5, max(3, 5));
    EXPECT_EQ(10, max(10, 2));
}

TEST(MaxTest, HandlesNegativeNumbers) {
    EXPECT_EQ(-1, max(-1, -5));
    EXPECT_EQ(-2, max(-2, -10));
}

TEST(MaxTest, HandlesZero) {
    EXPECT_EQ(0, max(0, -5));
    EXPECT_EQ(5, max(0, 5));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
