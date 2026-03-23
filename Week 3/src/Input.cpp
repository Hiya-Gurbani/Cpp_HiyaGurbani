#include "Input.h"
#include "Constants.h"
#include <iostream>
#include <climits>
#include <limits>

bool isInputStreamValid() {
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

bool isValidRange(InputType input, int value) {
    bool isValid = true;
    int minValue, maxValue;

    switch (input)
    {
        case CHOICE:
        minValue = MIN_CHOICE;
        maxValue = MAX_CHOICE;
        break;

        case MATRICES_NUMBER:
        minValue = MIN_MATRICES;
        maxValue = MAX_MATRICES;
        break;

        case ROWS:
        minValue = MIN_ROWS;
        maxValue = MAX_ROWS;
        break;

        case COLUMNS:
        minValue = MIN_COLS;
        maxValue = MAX_COLS;
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

int inputValue(InputType input) {
    int value;
    while (true) 
    {
        std::cin >> value;
        if (!isInputStreamValid())
        {
            std::cout << "Invalid Input. Please enter an integer: ";
        }
        else if (!isValidRange(input, value))
        {
            std::cout << "Invalid Value. Please enter an integer in range: ";
        } 
        else
        {
            break;
        }
    }
    return value;
}

double inputValue() {
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
            std::cout << "Invalid Input. Please enter a number: ";
        }
    }
    
    return value;
}