#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Source.h"
//#include "C:\Users\lavre\algds2024\lab1\LabDataProject1\Source.cpp"

TEST(MinFunction_Test, ThreeIntegers_MinimumReturned) {
    // Arrange
    int a = 5, b = 10, c = 3;

    // Act
    int result = Min(a, b, c);

    // Assert
    EXPECT_EQ(result, 3);
}

TEST(MinFunction_Test, ThreeIntegers_EqualMinimumReturned) {
    // Arrange
    int a = 5, b = 3, c = 5;

    // Act
    int result = Min(a, b, c);

    // Assert
    EXPECT_EQ(result, 3);
}

TEST(MinFunction_Test, ThreeIntegers_MaximumReturned) {
    // Arrange
    int a = 10, b = 20, c = 30;

    // Act
    int result = Min(a, b, c);

    // Assert
    EXPECT_EQ(result, 10);
}

int Car(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
