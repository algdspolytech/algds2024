#include "lab2.h"
#include <limits.h>
#include<string.h>
#include "gtest/gtest.h"

using namespace std;

namespace {
TEST(InsertTest, InsertT1) {
  char result[1000] = "\0";
  struct Node* T1 = createNode(3, 1);

  insert(&T1, 2, 2);
  PrintTree(T1, result);
  EXPECT_EQ(string("(3,1)(2,2)"), string(result));
  memset(result,0,1000);

  insert(&T1, 4, 5);
  PrintTree(T1, result);
  EXPECT_EQ(string("(3,1)(2,2)(4,5)"), string(result));
}

TEST(InsertTest, InsertT2) {
  char result[1000] = "\0";
  struct Node* T2 = createNode(5, 4);
  insert(&T2, 6, 6);
  insert(&T2, 7, 0);
  insert(&T2, 8, 15);
  PrintTree(T2, result);
  EXPECT_EQ(string("(7,0)(5,4)(6,6)(8,15)"), string(result));
}

TEST(MergeTest, Merge){
    char result[1000] = "\0";

    struct Node* T1 = createNode(3, 1);
    insert(&T1, 2, 2);
    insert(&T1, 4, 5);  

    struct Node* T2 = createNode(5, 4);
    insert(&T2, 6, 6);
    insert(&T2, 7, 0);
    insert(&T2, 8, 15);

    struct Node* mergedRoot = NULL;
    merge(&T1, &T2);
    mergedRoot = T1;

    PrintTree(mergedRoot,result);
    EXPECT_EQ(string("(7,0)(3,1)(2,2)(5,4)(4,5)(6,6)(8,15)"), string(result));

}

TEST(SplitTest, SplitTreap) {
  char result[1000] = "\0";
  struct Node* T = createNode(3, 1);
  insert(&T, 2, 2);
  insert(&T, 4, 5);  
  insert(&T, 6, 6);
  insert(&T, 7, 0);
  insert(&T, 8, 15);
  insert(&T, 5, 4);

  struct Node* T1;
  struct Node* T2;
  splitTreap(T, 4, &T1, &T2);

  PrintTree(T1, result);
  EXPECT_EQ(string("(3,1)(2,2)(4,5)"), string(result));

  memset(result, 0, 100);
  PrintTree(T2, result);
  EXPECT_EQ(string("(7,0)(5,4)(6,6)(8,15)"), string(result));
}
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}