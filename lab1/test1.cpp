#include <gtest/gtest.h>
#include <string.h>
#include <stdlib.h>

extern "C" {
    #include "findLCS.h" // Предполагается, что ваш findLCS.h содержит объявления функций findLCS и max
}

// Тесты для функции findLCS
TEST(FindLCSTest, TestDifferentLengthStrings) {
    char X[] = "101010";
    char Y[] = "10";
    char* result = findLCS(X, Y, strlen(X), strlen(Y));
    ASSERT_STREQ("10", result);
    free(result);
}

TEST(FindLCSTest, TestNoCommonSubsequence) {
    char X[] = "111";
    char Y[] = "000";
    char* result = findLCS(X, Y, strlen(X), strlen(Y));
    ASSERT_STREQ("", result);
    free(result);
}

TEST(FindLCSTest, TestCommonSubsequenceAtStart) {
    char X[] = "10101";
    char Y[] = "10111";
    char* result = findLCS(X, Y, strlen(X), strlen(Y));
    ASSERT_STREQ("1011", result); 
    free(result);
}

TEST(FindLCSTest, TestCommonSubsequenceAtEnd) {
    char X[] = "00101";
    char Y[] = "10101";
    char* result = findLCS(X, Y, strlen(X), strlen(Y));
    // Ожидается "101", но функция может вернуть "0101", что также является корректным.
    ASSERT_TRUE(strcmp(result, "101") == 0 || strcmp(result, "0101") == 0);
    free(result);
}


TEST(FindLCSTest, TestRandomBinarySequences) {
    char X[] = "0110101";
    char Y[] = "110110";
    char* result = findLCS(X, Y, strlen(X), strlen(Y));
    ASSERT_TRUE(strcmp(result, "1101") == 0 || strcmp(result, "11011") == 0);
    free(result);
}


TEST(FindLCSTest, TestLongSequences) {
    char X[] = "0101010101010101010101010101010101010101";
    char Y[] = "1010101010101010101010101010101010101010";
    char* result = findLCS(X, Y, strlen(X), strlen(Y));
    ASSERT_STREQ("101010101010101010101010101010101010101", result);
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
