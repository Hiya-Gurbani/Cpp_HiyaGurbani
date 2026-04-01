#ifndef VALIDATOR_TEST_H
#define VALIDATOR_TEST_H

#include <gtest/gtest.h>

class GivenValidatorValidChoiceTest : public ::testing::TestWithParam<std::string> {};

class GivenValidatorInvalidChoiceTest : public ::testing::TestWithParam<std::string> {};

#endif
