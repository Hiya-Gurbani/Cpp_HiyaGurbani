#include <gtest/gtest.h>

bool isEven(int num) {
    return num % 2 == 0;
}

//Fixture : with nothing
class IsEvenTest : public ::testing::TestWithParam<int> {};

TEST_P(IsEvenTest, HandlesEvenNumbers) {
    int value = GetParam();
    EXPECT_EQ(isEven(value), value % 2 == 0);
    // EXPECT_TRUE(isEven(value));
}

INSTANTIATE_TEST_SUITE_P(
    EvenValues,         //Name for this 
    IsEvenTest,         //Name of test fixture
    ::testing::Values(0, 1, 2, 3, 4, 5, 10, 11) //Values of parameters
);

// g++ test.cpp -lgtest -lgtest_main -pthread -o run_tests
// ./run_tests

