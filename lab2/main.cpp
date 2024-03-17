/* 2023/2024 - 2 semester, Data design in applications
 * Author: Pavel Dvas, 5030102/20002
 * File Name: main.cpp
 * Last Updated: 17.03.2024
 */
#include <gtest/gtest.h>

#include "avl.h"

/*** Testing ***/
TEST(AVL_Test, HandleMultipleInsertDelete)
{
  Node *root = NULL;
  char Str[200];
  memset(Str, 0, sizeof(Str));

  root = Insert(root, 10);
  root = Insert(root, 20);
  root = Insert(root, 30);
  root = Insert(root, 40);
  root = Insert(root, 50);
  root = Insert(root, 25);

  PrintTree(root, Str);
  EXPECT_STREQ(Str, "30(20(10(*,*),25(*,*)),40(*,50(*,*)))");

  root = DeleteNode(root, 30);
  root = DeleteNode(root, 25);

  memset(Str, 0, sizeof(Str));
  PrintTree(root, Str);
  EXPECT_STREQ(Str, "40(20(10(*,*),*),50(*,*))");
}

TEST(AVL_Test, HandleSingleInput)
{
  Node *Root = Insert(NULL, 30);
  char Str[200];
  memset(Str, 0, sizeof(Str));

  PrintTree(Root, Str);
  EXPECT_STREQ(Str, "30(*,*)");
}

TEST(AVL_Test, HandleSingleDelete)
{
  Node *root = NULL;
  char Str[200];
  memset(Str, 0, sizeof(Str));

  root = Insert(root, 10);
  root = Insert(root, 20);
  root = Insert(root, 30);

  root = DeleteNode(root, 20);
  PrintTree(root, Str);

  EXPECT_STREQ(Str, "30(10(*,*),*)");
}

/* Main program function.
 * ARGUMENTS: None.
 * RETURNS:
 *   (int) - return code
 */
int main( void )
{
  testing::InitGoogleTest();

  RUN_ALL_TESTS();

  return 0;
} /* End of 'main' function */

/* END OF 'main.cpp' FILE */
