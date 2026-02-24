#include <gtest/gtest.h>

TEST(CalculatorTest, ValidDivision) {
    Calculator calc;

    // isValidInput(10, 2) runs internally — returns true
    EXPECT_EQ(calc.divide(10, 2), 5);
}

TEST(CalculatorTest, DivisionByZeroReturnsMinusOne) {
    Calculator calc;

    // isValidInput(10, 0) runs internally — returns false
    EXPECT_EQ(calc.divide(10, 0), -1);
}
