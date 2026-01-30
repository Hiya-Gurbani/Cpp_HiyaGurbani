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

// bool isInputStreamValid() {
//     if (std::cin.fail()) 
//     {
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         return false;
//     }
    
//     // Skip trailing whitespace (spaces and tabs)
//     char nextChar;
//     while (std::cin.peek() == ' ' || std::cin.peek() == '\t') {
//         std::cin.get();
//     }
    
//     // After skipping spaces, next character must be newline
//     nextChar = std::cin.peek();
//     if (nextChar != '\n' && nextChar != EOF) 
//     {
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         return false;
//     }
    
//     return true;
// }

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