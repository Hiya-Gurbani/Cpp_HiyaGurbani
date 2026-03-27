#include "Validator.h"

bool Validator::isValidChoice(const std::string& choice) {
    bool isValid = false;

    if (choice.length() != 1)
    {
        Logger::printMessage(Constants::MSG_INVALID_CHOICE);
    }
    else if (choice[0] != Constants::CHOICE_YES && choice[0] != Constants::CHOICE_YES_UPPER &&
        choice[0] != Constants::CHOICE_NO && choice[0] != Constants::CHOICE_NO_UPPER)
    {
        Logger::printMessage(Constants::MSG_INVALID_CHOICE);
    }
    else
    {
        isValid = true;
    }

    return isValid;
}
