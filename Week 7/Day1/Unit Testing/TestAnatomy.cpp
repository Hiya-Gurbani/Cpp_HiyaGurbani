#include <gtest/gtest.h>

TEST(TestSuiteName, TestCaseName) {
    // Arrange — set up data
    int a = 5;
    int b = 3;

    // Act — call the function
    int result = a + b;

    // Assert — verify the result
    EXPECT_EQ(result, 8);
}