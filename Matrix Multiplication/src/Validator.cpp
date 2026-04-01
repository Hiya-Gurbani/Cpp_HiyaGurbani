#include "../inc/Validator.h"
#include "../inc/Constants.h"
#include "../inc/Logger.h"
#include <iostream>
#include <limits>

bool Validator::isInputStreamValid() {
    bool isValidStream = false;
    if (std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), Constants::NEW_LINE);
    }
    else
    {
        while (std::cin.peek() == Constants::WHITESPACE || std::cin.peek() == Constants::TAB) 
        {
            std::cin.get();
        }
    
        if (std::cin.peek() == Constants::NEW_LINE) 
        {
            isValidStream = true;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return isValidStream;
}

bool Validator::isValidChoice(const std::string& choice) {
    bool isValid = false;

    if (choice.length() == 1) {
        char character = choice[0];

        if (character == Constants::CHOICE_YES || character == Constants::CHOICE_NO )
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
