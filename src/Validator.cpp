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

