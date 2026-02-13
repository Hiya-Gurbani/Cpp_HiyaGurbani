#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "Constants.h"

class Validator {
    static bool isValidDigitsOnly(std::string& input, size_t expectedLength);
    static bool isValidName(std::string& input);
    static bool isValidEmail(std::string& email);
    static bool isValidAmount(double amount, double minAmount = 0.0);

public:
    static bool isInputStreamValid();
    static bool isValidInput(std::string& input, Constants::InputType type);
};

#endif
