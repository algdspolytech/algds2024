/* 2023/2024 - 2 semester, Data design in applications
 * Author: Pavel Dvas, 5030102/20002
 * File Name: main.cpp
 * Last Updated: 15.02.2024
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <gtest/gtest.h>

#include "lcs.h"

/*** Testing ***/
TEST(LCS_Test, HandleSame)
{
    EXPECT_STREQ(FindLCS("1111", "1111"), "1111");
}

TEST(LCS_Test, HandleEmpty)
{
    EXPECT_STREQ(FindLCS("", ""), "");
}

TEST(LCS_Test, HandleNotSame)
{
    EXPECT_STREQ(FindLCS("110100101", "10010101"), "1010101");
}

TEST(LCS_Test, HandleWrong)
{
    EXPECT_STRNE(FindLCS("110100101", "10010101"), "101");
}

/* Transform int number to binary representation function.
 * ARGUMENTS:
 *   - number to transform:
 *       unsigned X;
 *   - pointer to an array to store the representation:
 *       char **Bin;
 * RETURNS: None.
 */
void IntToBin( unsigned X, char **Bin )
{
  int NumLen = (int)ceil(log(X) / log(2)), i;

  if (((*Bin) = (char *)malloc(NumLen + 1)) == NULL)
    return;

  for (i = NumLen - 1; i >= 0; i--)
    if (X & (1 << i))
      (*Bin)[NumLen - 1 - i] = '1';
    else
      (*Bin)[NumLen - 1 - i] = '0';
  (*Bin)[NumLen] = 0;
} /* End of 'IntToBin' function */

/* Main program function.
 * ARGUMENTS: None.
 * RETURNS:
 *   (int) - return code
 */
int main( void )
{
    char *BinX, *BinY;
    unsigned x, y;
    testing::InitGoogleTest();

    RUN_ALL_TESTS();

    /* Testing on the input from stdin */
    /*
    printf("Input two numbers(which'll be transformed into binary)\nX:");
    scanf("%d", &x);
    printf("Y:");
    scanf("%d", &y);

    IntToBin(x, &BinX);
    IntToBin(y, &BinY);

    FindLCS(BinX, BinY);

    free(BinX);
    free(BinY);
     */
} /* End of 'main' function */

/* END OF 'main.cpp' FILE */
