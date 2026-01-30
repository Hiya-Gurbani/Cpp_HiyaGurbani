#include "AllHeaders.h"

bool isInputStreamValid() {
    bool isValid = true;

    if (std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        isValid = false;
    }
    
    while (std::cin.peek() == ' ' || std::cin.peek() == '\t') 
    {
        std::cin.get();
    }
    
    if (std::cin.peek() != '\n') 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        isValid = false;
    }
    
    return isValid;
}

void inputValue(int& value) {
    while (true) 
    {
        std::cin >> value;
        if (isInputStreamValid())
        {
            break;
        }
        else
        {
            std::cout << "Invalid Input. Please enter an integer: ";
        }
    }
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