#include "../inc/ValidatorTest.h"
#include "../../inc/Validator.h"

INSTANTIATE_TEST_SUITE_P(ValidChoices, GivenValidatorValidChoiceTest,
    ::testing::Values("y", "n"));

TEST_P(GivenValidatorValidChoiceTest, WhenValidChoiceEntered_ThenReturnsTrue) {
    EXPECT_TRUE(Validator::isValidChoice(GetParam()));
}

INSTANTIATE_TEST_SUITE_P(InvalidChoices, GivenValidatorInvalidChoiceTest,
    ::testing::Values("x", "N", "1", " ", "", "yn", "yy", "@"));

TEST_P(GivenValidatorInvalidChoiceTest, WhenInvalidChoiceEntered_ThenReturnsFalse) {
    EXPECT_FALSE(Validator::isValidChoice(GetParam()));
}
