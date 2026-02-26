#ifndef VALIDATOR_TEST_H
#define VALIDATOR_TEST_H

#include "Validator.h"
#include "Constants.h"
#include <gtest/gtest.h>

class ValidatorNameInvalidCharTest : public ::testing::TestWithParam<char> {};

class ValidatorEmailInvalidFormatTest : public ::testing::TestWithParam<std::string> {};

class ValidatorInvalidCharTest : public ::testing::TestWithParam<char> {};

#endif
