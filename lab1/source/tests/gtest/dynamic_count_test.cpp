#include <chrono>
#include <gtest/gtest.h>

extern "C" {
#include "dynamic_count.h"
#include "trivial.h"
}


TEST(countNumbersTest, countNumbers_n0k0_0Returned) {
    // arrange
    size_t n = 0, k = 0;
    size_t expected = 0;

    // act
    size_t actual = countNumbers(n, k);

    // assert
    ASSERT_EQ(expected, actual);
}


TEST(countNumbersTest, countNumbers_n11k1_11Returned) {
    // arrange
    size_t n = 11, k = 1;
    size_t expected = 11;

    // act
    size_t actual = countNumbers(n, k);

    // assert
    ASSERT_EQ(expected, actual);
}


TEST(countNumbersTest, countNumbers_n1k11_0Returned) {
    // arrange
    size_t n = 1, k = 11;
    size_t expected = 0;

    // act
    size_t actual = countNumbers(n, k);

    // assert
    ASSERT_EQ(expected, actual);
}


TEST(countNumbersTest, countNumbers_n2k17_2Returned) {
    // arrange
    size_t n = 2, k = 17;
    size_t expected = 2;

    // act
    size_t actual = countNumbers(n, k);

    // assert
    ASSERT_EQ(expected, actual);
}


TEST(countNumbersTest, countNumbers_n3k3_10Returned) {
    // arrange
    size_t n = 3, k = 3;
    size_t expected = 10;

    // act
    size_t actual = countNumbers(n, k);

    // assert
    ASSERT_EQ(expected, actual);
}

TEST(countNumbersTest, countNumbers_n10000k1000_Less100ms) {
    // arrange
    size_t n = 10000, k = 1000;
    auto expectedTime = std::chrono::milliseconds(100);

    auto elapsedTime = std::chrono::steady_clock::now();
    countNumbers(n, k);
    auto elapsedTimeMs = duration_cast<std::chrono::milliseconds>(elapsedTime -  std::chrono::steady_clock::now());

    EXPECT_LT(elapsedTimeMs, expectedTime);
}


TEST(countNumbersTest, countNumbers_small_n_all_k) {
    // arrange
    size_t const nMax = 7;
    size_t const kMax = 65;

    for (size_t n = 1; n <= nMax; n++) {
        for (size_t k = 1; k <= kMax; k++) {
            size_t expected = countNumberViaEnum(n, k);
            // act
            size_t actual = countNumbers(n, k);

            // assert
            ASSERT_EQ(expected, actual);
        }
    }
}