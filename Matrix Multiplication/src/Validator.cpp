#include "../inc/Validator.h"
#include "../inc/Constants.h"
#include "../inc/Logger.h"

bool Validator::isValidChoice(const std::string& choice) {
    bool isValid = false;

    if (choice.length() == 1) {
        char character = choice[0];

        if (character == Constants::CHOICE_YES ||
            character == Constants::CHOICE_YES_UPPER ||
            character == Constants::CHOICE_NO ||
            character == Constants::CHOICE_NO_UPPER)
        {
            isValid = true;
        }
    }

    if (!isValid) 
    {
        Logger::printMessage(Constants::MSG_INVALID_CHOICE);
    }

    return isValid;
}
