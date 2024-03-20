#include "../find_max_incresing_subsequence.h"
#include <gtest/gtest.h>
#include <vector>
using namespace std;
// Тестирование функции find_max_increasing_subsequence
TEST(FindMaxIncreasingSubsequenceTest, Example1) {
    int sequence[] = {3, 10, 2, 1, 20};
    int sequence_length = sizeof(sequence) / sizeof(sequence[0]);
    int length_of_subsequence;
    int *subsequence = find_max_increasing_subsequence(sequence, sequence_length, &length_of_subsequence);
    ASSERT_NE(subsequence, nullptr); // Проверка на нулевой указатель
    vector<int> result_subsequence = {3, 10, 20};
    EXPECT_EQ(length_of_subsequence, result_subsequence.size());
    for (int i = 0; i < length_of_subsequence; ++i) {
        EXPECT_EQ(subsequence[i], result_subsequence[i]);
    }
    free(subsequence); // Освобождение памяти
}

TEST(FindMaxIncreasingSubsequenceTest, Example2) {
    int sequence[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int sequence_length = sizeof(sequence) / sizeof(sequence[0]);
    int length_of_subsequence;
    int *subsequence = find_max_increasing_subsequence(sequence, sequence_length, &length_of_subsequence);
    ASSERT_NE(subsequence, nullptr);
    vector<int> result_subsequence = {10, 22, 33, 41, 60, 80};
    EXPECT_EQ(length_of_subsequence, result_subsequence.size());
    for (int i = 0; i < length_of_subsequence; ++i) {
        EXPECT_EQ(subsequence[i], result_subsequence[i]);
    }
    free(subsequence);
}

TEST(FindMaxIncreasingSubsequenceTest, Example3) {
    int sequence[] = {50, 3, 10, 7, 40, 80};
    int sequence_length = sizeof(sequence) / sizeof(sequence[0]);
    int length_of_subsequence;
    int *subsequence = find_max_increasing_subsequence(sequence, sequence_length, &length_of_subsequence);
    ASSERT_NE(subsequence, nullptr);
    vector<int> result_subsequence = {3, 7, 40, 80};
    EXPECT_EQ(length_of_subsequence, result_subsequence.size());
    for (int i = 0; i < length_of_subsequence; ++i) {
        EXPECT_EQ(subsequence[i], result_subsequence[i]);
    }
    free(subsequence);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
