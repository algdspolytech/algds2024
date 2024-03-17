#include <stdio.h>
#include <iostream>
#include <gtest\gtest.h>
 
#ifdef __cplusplus
extern "C" {
#endif
 
#include "func.h"
 
#ifdef __cplusplus
}
#endif
 
TEST(testCase, test0)
{
    EXPECT_EQ(count_numbers(1,3),1);
}

TEST(testCase, test1)
{
    EXPECT_EQ(count_numbers(2,6),7);
}

TEST(testCase, test2)
{
    EXPECT_EQ(count_numbers(3,12),73);
}
 
int main(int argc,char**argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}