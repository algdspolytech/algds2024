#include "levenshtein.h"
#include <gtest/gtest.h>

// Тестирование функции minimum
TEST(MinimumFunction, EqualValues) {
    EXPECT_EQ(5, minimum(5, 5, 5));
}

TEST(MinimumFunction, FirstValueLeast) {
    EXPECT_EQ(1, minimum(1, 2, 3));
}

TEST(MinimumFunction, SecondValueLeast) {
    EXPECT_EQ(2, minimum(3, 2, 5));
}

TEST(MinimumFunction, ThirdValueLeast) {
    EXPECT_EQ(4, minimum(6, 5, 4));
}

// Тестирование функции levenshteinDistance
TEST(LevenshteinDistanceFunction, EmptyStrings) {
    wchar_t x[] = L"";
    wchar_t y[] = L"";
    int m = wcslen(x);
    int n = wcslen(y);
    EXPECT_EQ(0, levenshteinDistance(x, m, y, n));
}

TEST(LevenshteinDistanceFunction, OneEmptyString) {
    wchar_t x[] = L"";
    wchar_t y[] = L"test";
    int m = wcslen(x);
    int n = wcslen(y);
    EXPECT_EQ(4, levenshteinDistance(x, m, y, n));
}

TEST(LevenshteinDistanceFunction, IdenticalStrings) {
    wchar_t x[] = L"googletest";
    wchar_t y[] = L"googletest";
    int m = wcslen(x);
    int n = wcslen(y);
    EXPECT_EQ(0, levenshteinDistance(x, m, y, n));
}

TEST(LevenshteinDistanceFunction, DifferentStrings) {
    wchar_t x[] = L"kitten";
    wchar_t y[] = L"sitting";
    int m = wcslen(x);
    int n = wcslen(y);
    EXPECT_EQ(3, levenshteinDistance(x, m, y, n));
}

// Точка входа для Google test
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}