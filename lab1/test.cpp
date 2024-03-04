#include "pch.h"
#include "gtest/gtest.h"
#include "../Laba1.c"

//extern "C" {
//#include "../Laba1.c"
//}

TEST(PrintNumberTest, Positive) {
    testing::internal::CaptureStdout();
    PrintNumber(3, 6);
    std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "006\n015\n024\n033\n042\n051\n060\n105\n114\n123\n132\n141\n150\n204\n213\n222\n231\n240\n303\n312\n321\n330\n402\n411\n420\n501\n510\n600\n");
}

TEST(PrintNumberTest, Negative) {
    testing::internal::CaptureStdout();
    PrintNumber(-2, 5);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");

    testing::internal::CaptureStdout();
    PrintNumber(-10, -6);
    std::string output2 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output2, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");

    testing::internal::CaptureStdout();
    PrintNumber(4, -2);
    std::string output3 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output3, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");
}

TEST(PrintNumberTest, Zero) {
    testing::internal::CaptureStdout();
    PrintNumber(0, 14);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");

    testing::internal::CaptureStdout();
    PrintNumber(4, 0);
    std::string output2 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output2, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");

    testing::internal::CaptureStdout();
    PrintNumber(0, 0);
    std::string output3 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output3, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");
}

TEST(PrintNumberTest, Double) {
    testing::internal::CaptureStdout();
    PrintNumber(2.3, 12);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");

    testing::internal::CaptureStdout();
    PrintNumber(3.5, 2.4);
    std::string output2 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output2, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");

    testing::internal::CaptureStdout();
    PrintNumber(6, 7.1);
    std::string output3 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output3, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");
}

TEST(PrintNumberTest, Words) {
    testing::internal::CaptureStdout();
    PrintNumber('cbe', 9);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");

    testing::internal::CaptureStdout();
    PrintNumber('dn', 'd');
    std::string output2 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output2, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");

    testing::internal::CaptureStdout();
    PrintNumber(4, 'dk');
    std::string output3 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output3, "¬ведите корректные данные: <значность сумма> (целые положительные числа больше 0)\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}