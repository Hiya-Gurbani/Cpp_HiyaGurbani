#include "AllHeaders.h"

bool isInputStreamValid() {
    if (std::cin.fail() || std::cin.peek() != '\n') 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
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
            std::cout << "Invalid Input. Only integers allowed. Enter again: ";
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
            std::cout << "Invalid Input. Only double allowed. Enter again: ";
        }
    }
}