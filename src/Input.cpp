#include "Input.h"
#include <iostream>
#include <limits>

bool isInputStreamValid() {
    bool isValid = false;
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
            isValid = true;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return isValid;
}

int inputValue(int minValue, int maxValue) {
    int value;
    while (true) 
    {
        std::cin >> value;
        if (!isInputStreamValid())
        {
            std::cout << "Invalid Input. Please enter an integer: ";
        }
        else if (value < minValue || value > maxValue)
        {
            std::cout << "Invalid Value. Please enter an integer in range "
                      <<  minValue << "-" << maxValue << ": ";
        } 
        else
        {
            break;
        }
    }
    return value;
}

void inputValue(double& value) {
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
}