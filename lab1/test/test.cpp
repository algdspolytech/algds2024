#include "gtest/gtest.h"
#include <string>
#include "../Project1/funcs.h"


TEST(FindSolTest, Simmilar) {
    std::string stringX = "polytech\0";
    std::string stringY = "polytech\0";
    int d = 1;
    int i = 1;
    int c = 1;
    FindSol(&stringX[0], &stringY[0], d, i, c);
    std::string expected = "polytech\0";

    EXPECT_STREQ(&stringX[0], &expected[0]);
} 

TEST(FindSolTest, NotSimmilar_D1I1C1) {
    std::string stringX = "polytech\0";
    std::string stringY = "moscow\0";
    int d = 1;
    int i = 1;
    int c = 1;
    FindSol(&stringX[0], &stringY[0], d, i, c);
    std::string expected = "moscow\0";

    EXPECT_STREQ(&stringX[0], &expected[0]);
}

TEST(FindSolTest, NotSimmilar_D5I1C3) {
    std::string stringX = "polytech\0";
    std::string stringY = "moscow\0";
    int d = 5;
    int i = 1;
    int c = 3;
    FindSol(&stringX[0], &stringY[0], d, i, c);
    std::string expected = "moscow\0";

    EXPECT_STREQ(&stringX[0], &expected[0]);
}




