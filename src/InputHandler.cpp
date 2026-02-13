#include "InputHandler.h"
#include "Constants.h"
#include "Logger.h"
#include "Validator.h"
#include <iostream>

double& InputHandler::inputValue(double& value) {
    while (true) 
    {
        std::cin >> value;
        if (Validator::isInputStreamValid())
        {
            break;
        }
        else
        {
            std::cout << Logger::MSG_INVALID_NUMBER;
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
            std::cout << Logger::MSG_INVALID_INTEGER;
        }
        else
        {
            break;
        }
    }

    return value;
}

void InputHandler::removeLeadingAndTrailingWhitespaces(std::string& input) {
    size_t first = input.find_first_not_of(" \t\n\r");
    size_t last  = input.find_last_not_of(" \t\n\r");

    if (first == std::string::npos)
    {
        input = "";
    }

    input = input.substr(first, (last - first + 1));
}

void InputHandler::inputString(std::string& input) {
    while (true) 
    {
        std::getline(std::cin, input);
        removeLeadingAndTrailingWhitespaces(input);
        if (input == "")
        {
            std::cout << "Input cannot be empty! Enter again: ";
        }
        else
        {
            break;
        }
    }
}