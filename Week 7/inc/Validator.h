#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "Constants.h"

class Validator {
    static bool isValidDigitsOnly(std::string& input, size_t expectedLength);
    static bool isValidName(std::string& input);
    static bool isValidEmail(std::string& email);

public:
    static bool isInputStreamValid();
    static bool isValidInput(std::string& input, Constants::InputType type);
};

#endif
