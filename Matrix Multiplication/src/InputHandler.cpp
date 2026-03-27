#include <iostream>

bool InputHandler::isInputStreamValid() {
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

int InputHandler::inputValue(InputType input) {
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

double InputHandler::inputValue() {
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

char Utility::getUserChoice() {
    std::string choice;

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
