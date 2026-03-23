#include "InputHandler.h"
#include "Constants.h"
#include "Logger.h"
#include "Validator.h"
#include "Display.h"
#include <iostream>

double& InputHandler::inputValue(double& value) {
    while (true) 
    {
        std::cin >> value;
        if (!Validator::isInputStreamValid())
        {
            Display::printMessage(Logger::MSG_INVALID_NUMBER);
        }
        else
        {
            break;
        }
    }
    
    return value;
}

int& InputHandler::inputValue(int& value) {
    while (true) 
    {
        std::cin >> value;
        if (!Validator::isInputStreamValid())
        {
            Display::printMessage(Logger::MSG_INVALID_INTEGER);
        }
        else
        {
            break;
        }
    }

    return value;
}

void InputHandler::removeLeadingAndTrailingWhitespaces(std::string& input) {
    size_t first = input.find_first_not_of(Constants::WHITESPACE_CHARS);
    size_t last  = input.find_last_not_of(Constants::WHITESPACE_CHARS);

    if (first == std::string::npos)
    {
        input = Constants::EMPTY_STRING;
    }
    else
    {
        input = input.substr(first, (last - first + 1));
    }
}

void InputHandler::inputString(std::string& input, Constants::InputType type) {
    while (true) 
    {
        std::getline(std::cin, input);
        removeLeadingAndTrailingWhitespaces(input);
        if (input == Constants::EMPTY_STRING)
        {
            Display::printMessage(Logger::MSG_EMPTY_INPUT);
        }
        else if (!Validator::isValidInput(input, type))
        {
            Display::printMessage(Logger::MSG_ENTER_AGAIN);
        }
        else
        {
            break;
        }
    }
}
