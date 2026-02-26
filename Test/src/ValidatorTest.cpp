#include "Validator.h"
#include "Constants.h"
#include <gtest/gtest.h>

// Name Tests

TEST(ValidatorNameTest, ExactMinLength_AllAplha_ReturnsTrue) {
    std::string input(Constants::MIN_NAME_LENGTH, 'A');
    EXPECT_TRUE(Validator::isValidInput(input, Constants::InputType::NAME));
}

TEST(ValidatorNameTest, AboveMinLength_WithSpace_ReturnsTrue) {
    std::string input(Constants::MIN_NAME_LENGTH + 1, 'A');
    input[Constants::MIN_NAME_LENGTH - 1] = ' ';
    EXPECT_TRUE(Validator::isValidInput(input, Constants::InputType::NAME));
}

TEST(ValidatorNameTest, BelowMinLength_ReturnsFalse) {
    std::string input(Constants::MIN_NAME_LENGTH - 1, 'A');
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::NAME));
}

class ValidatorNameInvalidCharTest : public ::testing::TestWithParam<char> {};

TEST_P(ValidatorNameInvalidCharTest, ContainsInvalidChar_ReturnsFalse) {
    std::string input(Constants::MIN_NAME_LENGTH + 1, 'A');
    input[Constants::MIN_NAME_LENGTH - 1] = GetParam();
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::NAME));
}

INSTANTIATE_TEST_SUITE_P(InvalidChars, ValidatorNameInvalidCharTest,
    ::testing::Values('1', '@', '3', '#')
);

// Email Tests

TEST(ValidatorEmailTest, CorrectEmailFormat_ReturnsTrue) {
    std::string input = "hiya@gmail.com";
    EXPECT_TRUE(Validator::isValidInput(input, Constants::InputType::EMAIL));
}

class ValidatorEmailInvalidFormatTest : public ::testing::TestWithParam<std::string> {};

TEST_P(ValidatorEmailInvalidFormatTest, InvalidFormat_ReturnsFalse) {
    std::string input = GetParam();
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::EMAIL));
}

INSTANTIATE_TEST_SUITE_P(InvalidEmails, ValidatorEmailInvalidFormatTest,
    ::testing::Values("hiyagmail.com", "hiya@gmailcom", "hiya@gmail.")
);

// Phone Number Tests

TEST(ValidatorPhoneTest, CorrectPhone_ReturnsTrue) {
    std::string input(Constants::PHONE_LENGTH, '5');
    EXPECT_TRUE(Validator::isValidInput(input, Constants::InputType::PHONE));
}

TEST(ValidatorPhoneTest, BelowLength_ReturnsFalse) {
    std::string input(Constants::PHONE_LENGTH - 1, '5');
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::PHONE));
}

TEST(ValidatorPhoneTest, AboveLength_ReturnsFalse) {
    std::string input(Constants::PHONE_LENGTH + 1, '5');
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::PHONE));
}

// Pin Tests

TEST(ValidatorPinTest, CorrectPin_ReturnsTrue) {
    std::string input(Constants::PIN_LENGTH, '5');
    EXPECT_TRUE(Validator::isValidInput(input, Constants::InputType::PIN));
}

TEST(ValidatorPinTest, BelowLength_ReturnsFalse) {
    std::string input(Constants::PIN_LENGTH - 1, '5');
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::PIN));
}

TEST(ValidatorPinTest, AboveLength_ReturnsFalse) {
    std::string input(Constants::PIN_LENGTH + 1, '5');
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::PIN));
}

// Account Number Tests

TEST(ValidatorAccountNumberTest, CorrectAccountNumber_ReturnsTrue) {
    std::string input(Constants::ACCOUNT_NUMBER_LENGTH, '5');
    EXPECT_TRUE(Validator::isValidInput(input, Constants::InputType::ACCOUNT_NUMBER));
}

TEST(ValidatorAccountNumberTest, BelowLength_ReturnsFalse) {
    std::string input(Constants::ACCOUNT_NUMBER_LENGTH - 1, '5');
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::ACCOUNT_NUMBER));
}

TEST(ValidatorAccountNumberTest, AboveLength_ReturnsFalse) {
    std::string input(Constants::ACCOUNT_NUMBER_LENGTH + 1, '5');
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::ACCOUNT_NUMBER));
}

class ValidatorInvalidCharTest : public ::testing::TestWithParam<char> {};

TEST_P(ValidatorInvalidCharTest, PhoneContainsInvalidChar_ReturnsFalse) {
    std::string input(Constants::PHONE_LENGTH, '5');
    input[Constants::PHONE_LENGTH - 1] = GetParam();
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::PHONE));
}

TEST_P(ValidatorInvalidCharTest, PinContainsInvalidChar_ReturnsFalse) {
    std::string input(Constants::PIN_LENGTH, '5');
    input[Constants::PIN_LENGTH - 1] = GetParam();
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::PIN));
}

TEST_P(ValidatorInvalidCharTest, AccountNumberContainsInvalidChar_ReturnsFalse) {
    std::string input(Constants::ACCOUNT_NUMBER_LENGTH, '5');
    input[Constants::ACCOUNT_NUMBER_LENGTH - 1] = GetParam();
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::ACCOUNT_NUMBER));
}

INSTANTIATE_TEST_SUITE_P(InvalidChars, ValidatorInvalidCharTest,
    ::testing::Values('A', '@', 'b', '#')
);

// Password Tests

TEST(ValidatorPasswordTest, ExactMinLength_AllAplha_ReturnsTrue) {
    std::string input(Constants::MIN_PASSWORD_LENGTH, 'x');
    EXPECT_TRUE(Validator::isValidInput(input, Constants::InputType::PASSWORD));
}

TEST(ValidatorPasswordTest, BelowMinLength_ReturnsFalse) {
    std::string input(Constants::MIN_PASSWORD_LENGTH - 1, 'x');
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::PASSWORD));
}

TEST(ValidatorPasswordTest, ContainsDigit_ReturnsTrue) {
    std::string input(Constants::MIN_PASSWORD_LENGTH + 1, 'x');
    input[Constants::MIN_PASSWORD_LENGTH - 1] = '1';
    EXPECT_TRUE(Validator::isValidInput(input, Constants::InputType::PASSWORD));
}

TEST(ValidatorPasswordTest, ContainsSpecialChar_ReturnsTrue) {
    std::string input(Constants::MIN_PASSWORD_LENGTH + 1, 'A');
    input[Constants::MIN_PASSWORD_LENGTH - 1] = '@';
    EXPECT_TRUE(Validator::isValidInput(input, Constants::InputType::PASSWORD));
}

