#include "Validator.h"
#include "Constants.h"
#include "Display.h"
#include "Logger.h"
#include <climits>
#include <iostream>
#include <limits>
#include <cctype>

bool Validator::isValidDigitsOnly(std::string& input, size_t expectedLength) {
    bool isValid = true;
    
    if (input.size() != expectedLength)  
    {
        Display::printInvalidLength(expectedLength);
        isValid = false;
    }
    else
    {
        for (char character : input)
        {
            if (!std::isdigit(character))  
            {
                isValid = false;
                Display::printMessage(Logger::MSG_INVALID_DIGITS);
                break;  
            }
        }
    }
    
    return isValid;
}

bool Validator::isValidName(std::string& input) {
    bool isValid = true;
    
    if (input.size() < Constants::MIN_NAME_LENGTH)  
    {
        Display::printInvalidNameLength(Constants::MIN_NAME_LENGTH);
        isValid = false;
    }
    else
    {
        for (char character : input)
        {
            if (!std::isalpha(character) && character != ' ')  
            {
                isValid = false;
                Display::printMessage(Logger::MSG_INVALID_NAME_CHARS);
                break;  
            }
        }
    }
    
    return isValid;
}

bool Validator::isValidEmail(std::string& email) {
    bool isValid = false;

    size_t atPosition = email.find('@');
    if (atPosition == std::string::npos) 
    {
        Display::printMessage(Logger::MSG_EMAIL_NO_AT);
    }
    else
    {
        size_t dotPosition = email.find('.', atPosition);
        if (dotPosition == std::string::npos || dotPosition == email.length() - 1) 
        {
            Display::printMessage(Logger::MSG_EMAIL_NO_DOMAIN);
        }
        else
        {
            isValid = true;
        }
    }
    
    return isValid;
}

bool Validator::isInputStreamValid() {
    bool isValidStream = false;
    if (std::cin.fail()) 
    {
        std::cin.clear();
    }
    else
    {
        while (std::cin.peek() == ' ' || std::cin.peek() == '\t') 
        {
            std::cin.get();
        }
    
        if (std::cin.peek() == '\n') 
        {
            isValidStream = true;
        }
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return isValidStream;
}

bool Validator::isValidInput(std::string& input, Constants::InputType type) {
    bool isValid = false;

    switch (type) {
        case Constants::InputType::NAME:
            isValid = isValidName(input);
            break;

        case Constants::InputType::EMAIL:
            isValid = isValidEmail(input);
            break;

        case Constants::InputType::PHONE:
            isValid = isValidDigitsOnly(input, Constants::PHONE_LENGTH);
            break;

        case Constants::InputType::ACCOUNT_NUMBER:
            isValid = isValidDigitsOnly(input, Constants::ACCOUNT_NUMBER_LENGTH);
            break;

        case Constants::InputType::PIN:
            isValid = isValidDigitsOnly(input, Constants::PIN_LENGTH);
            break;

        case Constants::InputType::PASSWORD:
            if (input.size() < Constants::MIN_PASSWORD_LENGTH) 
            {
                Display::printInvalidPasswordLength(Constants::MIN_PASSWORD_LENGTH);
                isValid = false;
            }
            isValid = true;
            break;

        default:
            isValid = true;
    }

    return isValid;
}