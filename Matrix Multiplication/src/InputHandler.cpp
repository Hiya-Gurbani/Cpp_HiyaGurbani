#include "../inc/InputHandler.h"
#include "../inc/Constants.h"
#include "../inc/Logger.h"
#include "../inc/Validator.h"
#include <iostream>
#include <limits>

int InputHandler::inputDimension() {
    int value;
    while (true) 
    {
        std::cin >> value;
        if (!Validator::isInputStreamValid())
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
        if (Validator::isInputStreamValid())
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

char InputHandler::inputChoice() {
    std::string choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), Constants::NEW_LINE);

    while (true)
    {
        Logger::printMessage(Constants::MSG_CONTINUE); 
        std::getline(std::cin, choice);

        if (Validator::isValidChoice(choice))
        {
            break;
        }     
    }

    return choice[0];
}
