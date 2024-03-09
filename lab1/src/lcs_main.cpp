#include <gtest/gtest.h>
extern "C" {
#include "Lab1_lcs.h"
}
TEST(LCS_Test, HandleSame)
{
    EXPECT_STREQ(LCS_Length("1101", "1101"), "1101");
}
TEST(LCS_Test, HandleEmpty)
{
    EXPECT_STREQ(LCS_Length("", ""), "");
}
TEST(LCS_Test, HandleNotSame1)
{
    EXPECT_STREQ(LCS_Length("0011", "110"), "11");
}
TEST(LCS_Test, HandleNotSame2)
{
    EXPECT_STREQ(LCS_Length("10110101", "101110101"), "10110101");
}
int main() {
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
    char str1[MAX_LEN];
    char str2[MAX_LEN];
    printf("enter the first sequence: ");
    fgets(str1, MAX_LEN, stdin);
    printf("enter the second sequence: ");
    fgets(str2, MAX_LEN, stdin);
    char* max_str = LCS_Length(str1, str2);
    free(max_str);
    return 0;
}