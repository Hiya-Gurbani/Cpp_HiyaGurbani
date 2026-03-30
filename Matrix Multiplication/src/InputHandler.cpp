#include "../inc/InputHandler.h"
#include "../inc/Constants.h"
#include "../inc/Logger.h"
#include "../inc/Validator.h"
#include <iostream>
#include <limits>

bool InputHandler::isInputStreamValid() {
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

int InputHandler::inputDimension() {
    int value;
    while (true) 
    {
        std::cin >> value;
        if (!isInputStreamValid())
        {
            Logger::printMessage(Constants::MSG_INVALID_INTEGER);
        }
        else if (value <= 0)
        {
            Logger::printMessage(Constants::MSG_OUT_OF_RANGE);
        } 
        else
        {
            break;
        }
    }
    return value;
}

double InputHandler::inputElement() {
    double value;

    while (true) 
    {
        std::cin >> value;
        if (isInputStreamValid())
        {
            break;
        }
        else
        {
            Logger::printMessage(Constants::MSG_INVALID_NUMBER);
        }
    }
    
    return value;
}

char InputHandler::getChoice() {
    std::string choice;

    while (true)
    {
        Logger::printMessage(Constants::MSG_CONTINUE); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), Constants::NEW_LINE);
        std::getline(std::cin, choice);

        if (Validator::isValidChoice(choice))
        {
            break;
        }     
    }

    return choice[0];
}
