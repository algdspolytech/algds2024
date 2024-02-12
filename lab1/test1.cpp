#include "lab1.h"
#include <limits.h>
#include "gtest/gtest.h"

namespace {
TEST(dTest, Empty) {
  EXPECT_EQ(3, d("","abc"));
  EXPECT_EQ(4, d("abdb",""));
  EXPECT_EQ(0, d("", ""));
}

TEST(dTest, Same){
    EXPECT_EQ(0, d("abc","abc"));
    EXPECT_EQ(0, d("ab4_", "ab4_"));
}

TEST(dTest, Random) {
  EXPECT_EQ(1, d("ab", "ac"));
  EXPECT_EQ(1, d("cat", "cats"));
  EXPECT_EQ(3, d("ptslddf","tsgldds"));
  EXPECT_EQ(7, d("abcdefghik","aebfhw"));
}
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
