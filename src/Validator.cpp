#include "Validator.h"
#include "Constants.h"
#include <climits>
#include <iostream>
#include <limits>

bool Validator::isInputStreamValid() {
    bool isValidStream = false;
    if (std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return isValidStream;
}

bool Validator::isValidRange(InputType input, int value) {
    bool isValid = true;
    int minValue, maxValue;

    switch (input)
    {
        case CHOICE:
        minValue = Constants::MIN_CHOICE;
        maxValue = Constants::MAX_CHOICE;
        break;

        case MATRICES_NUMBER:
        minValue = Constants::MIN_MATRICES;
        maxValue = Constants::MAX_MATRICES;
        break;

        case ROWS:
        minValue = Constants::MIN_ROWS;
        maxValue = Constants::MAX_ROWS;
        break;

        case COLUMNS:
        minValue = Constants::MIN_COLS;
        maxValue = Constants::MAX_COLS;
        break;

        default:
        minValue = INT_MIN;
        maxValue = INT_MAX;
    }

    if (value < minValue || value > maxValue)
    {
        isValid = false;
    }

    return isValid;
}