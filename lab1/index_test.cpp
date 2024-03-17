#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "index.h"

const int EMPTY_STRING_DISTANCE = 7;
const int SAME_STRINGS_DISTANCE = 0;
const int DIFFERENT_STRINGS_DISTANCE = 3;

TEST(editDistance, EmptyString_ReturnStringLength) {
    char x[] = "";
    char y[] = "tsgldds";
    ASSERT_EQ(editDistance(x, y), strlen(y));
    ASSERT_EQ(editDistance(y, x), strlen(y));
}

TEST(editDistance, SameStrings_ReturnZero) {
    char x[] = "abcdef";
    char y[] = "abcdef";
    ASSERT_EQ(editDistance(x, y), SAME_STRINGS_DISTANCE);
}

TEST(editDistance, DifferentStrings_ReturnValidDistance) {
    char x[] = "рtslddf";
    char y[] = "tsgldds";
    ASSERT_EQ(editDistance(x, y), DIFFERENT_STRINGS_DISTANCE);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}