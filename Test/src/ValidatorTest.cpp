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

TEST(ValidatorNameTest, ContainsDigit_ReturnsFalse) {
    std::string input(Constants::MIN_NAME_LENGTH + 1, 'A');
    input[Constants::MIN_NAME_LENGTH - 1] = '1';
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::NAME));
}

TEST(ValidatorNameTest, ContainsSpecialChar_ReturnsFalse) {
    std::string input(Constants::MIN_NAME_LENGTH + 1, 'A');
    input[Constants::MIN_NAME_LENGTH - 1] = '@';
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::NAME));
}

// Email Tests

TEST(ValidatorEmailTest, CorrectEmailFormat_ReturnsTrue) {
    std::string input = "hiya@gmail.com";
    EXPECT_TRUE(Validator::isValidInput(input, Constants::InputType::EMAIL));
}

TEST(ValidatorEmailTest, NoAtSign_ReturnsFalse) {
    std::string input = "hiyagmail.com";
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::EMAIL));
}

TEST(ValidatorEmailTest, NoDotAfterAt_ReturnsFalse) {
    std::string input = "hiya@gmailcom";
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::EMAIL));
}

TEST(ValidatorEmailTest, NoCharAfterDot_ReturnsFalse) {
    std::string input = "hiya@gmail.";
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::EMAIL));
}

//add another for @@

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

TEST(ValidatorPhoneTest, ContainsLetter_ReturnsFalse) {
    std::string input(Constants::PHONE_LENGTH, '5');
    input[Constants::PHONE_LENGTH - 1] = 'A';
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::PHONE));
}

TEST(ValidatorPhoneTest, ContainsSpecialChar_ReturnsFalse) {
    std::string input(Constants::PHONE_LENGTH, '5');
    input[Constants::PHONE_LENGTH - 1] = '@';
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

TEST(ValidatorPinTest, ContainsLetter_ReturnsFalse) {
    std::string input(Constants::PIN_LENGTH, '5');
    input[Constants::PIN_LENGTH - 1] = 'A';
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::PIN));
}

TEST(ValidatorPinTest, ContainsSpecialChar_ReturnsFalse) {
    std::string input(Constants::PIN_LENGTH, '5');
    input[Constants::PIN_LENGTH - 1] = '@';
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

TEST(ValidatorAccountNumberTest, ContainsLetter_ReturnsFalse) {
    std::string input(Constants::ACCOUNT_NUMBER_LENGTH, '5');
    input[Constants::ACCOUNT_NUMBER_LENGTH - 1] = 'A';
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::ACCOUNT_NUMBER));
}

TEST(ValidatorAccountNumberTest, ContainsSpecialChar_ReturnsFalse) {
    std::string input(Constants::ACCOUNT_NUMBER_LENGTH, '5');
    input[Constants::ACCOUNT_NUMBER_LENGTH - 1] = '@';
    EXPECT_FALSE(Validator::isValidInput(input, Constants::InputType::ACCOUNT_NUMBER));
}

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

