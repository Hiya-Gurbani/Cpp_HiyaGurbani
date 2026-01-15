#include <iostream>
#include <string>
#include <cmath>
#include <climits>

#define MIN_CHOICE 1
#define MAX_CHOICE 2

void removeWhitespace(const std::string& input, size_t& start, size_t end) {
    while (start < end && input[start] == ' ')
    {
        start++;
    }

    while (end > start && input[end - 1] == ' ')
    {
        end--;
    }
}

bool isValidInteger(const std::string& input, const size_t start, 
    const size_t end, unsigned short& choice ) {
    
        choice = 0;

        for (int index = start; index < end; index++)
        {
            if (input[index] >= '0' && input[index] <= '9')
            {
                int digit = input[index] - '0';
                if (choice > (USHRT_MAX - digit) / 10)
                {
                    return false;
                }
                choice = (choice * 10) + digit;
            }
            else
            {
                return false;
            }
        }

        return true;
}

int getChoice() {
    std::string input;
    unsigned short choice = 0;

    while (true) {
        std::getline(std::cin, input);

        size_t start = 0;
        size_t end = input.size();

        removeWhitespace(input, start, end);
        if (start >= end)
        {
            std::cout << "Empty Input! Enter again: ";
            continue;
        }

        if (!isValidInteger(input, start, end, choice))
        {
            std::cout << "Invalid Input! Enter again: ";
            continue;
        }

        if (choice < MIN_CHOICE || choice > MAX_CHOICE)
        {
            std::cout << "Invalid Choice! Enter again: ";
            continue;
        }

        return choice;
    }

    return choice;
}

bool isPositiveNumber(const char character, size_t& startIndex) {
    if (character == '-')
    {
        startIndex++;
        return false;
    }
    return true;
}

void handleDigit(double& value, double& decimalFactor, bool isDecimal, int digit) {
    if (!isDecimal)
    {
        value = (value * 10) + digit;
    }
    else
    {
        value += digit * decimalFactor;
        decimalFactor /= 10;
    }
}

int getDigitValue(char character) {
    if (character >= '0' && character <= '9')
    {
        return (character - '0');
    }
    else 
    {
        return ((std::tolower(character) - 'a') + 10);
    }

    return 0;
}

void handleHexadecimalDigit(double& value, double& decimalFactor, bool isDecimal, char character) {
    int digit = getDigitValue(character);

    if (!isDecimal)
    {
        value = (value * 16) + digit;
    }
    else
    {
        value += (digit * decimalFactor);
        decimalFactor /= 16;
    }
}

int getExponentSign(char character, int& index) {
    if (character == '-' || character == '+')
    {
        index++;
        if (character == '-')
        {
            return -1; 
        }
    }
    return 1;
}

int getExponentValue(const std::string& input, int& index) {
    int exponentValue = 0;

    while (index < input.size() && input[index] >= '0' && input[index] <= '9')
    {
        exponentValue = (exponentValue * 10) + (input[index] - '0');
        index++;
    }

    return exponentValue;
}

void handleExponent(const std::string& input, int& index, bool isHex, double& value) {
    index++;
    if (index >= input.size())
    {
        return;
    }

    int exponentSign = getExponentSign(input[index], index);
    int exponentValue = getExponentValue(input, index);

    int exponentBase = (isHex ? 2 : 10); 
    value *= pow(exponentBase, exponentSign * exponentValue);
}

bool handleCharacter(std::string& input, int& index, double& value, 
                    double& decimalFactor, bool& isDecimal, bool& isHex) {
    if (!isHex && input[index] >= '0' && input[index] <= '9')
    {
        handleDigit(value, decimalFactor, isDecimal, input[index] - '0');
    }
    else if (isHex && std::isxdigit(input[index]))
    {
        handleHexadecimalDigit(value, decimalFactor, isDecimal, input[index]);
    }
    else if (input[index] == '.')
    {
        if (isDecimal)
        {
            return false;
        }
        isDecimal = true;
    }
    else if (input[index] == 'e' || input[index] == 'E')
    {
        handleExponent(input, index, isHex, value);
        
        return false;
    }
    else if (input[index] == 'p' || input[index] == 'P')
    {
        handleExponent(input, index, isHex, value);
        return false;
    }
    else
    {
        return false;
    }

    return true;
}

double atof(std::string input) {
    double value = 0;
    size_t start = 0;
    size_t end = input.size();

    removeWhitespace(input, start, end);
    if (start >= end)
    {
        return value;
    }

    bool isPositive = isPositiveNumber(input[start], start);
    
    double decimalFactor = 0.1;
    bool isDecimal = false;
    bool isHex = false;

    if (start + 1 < end && input[start] == '0' && 
    (input[start + 1] == 'x' || input[start + 1] == 'X'))
    {
        isHex = true;
        start += 2;
        decimalFactor = 1.0 / 16;
    }
    
    for (int index = start; index < end; index++)
    {
        if (!handleCharacter(input, index, value, decimalFactor, isDecimal, isHex))
        {
            break;
        }
    }

    if (!isPositive && value != 0)
    {
        value = -value;
    }

    return value;
}

void printMenu() {
    std::cout << "\nOperations: \n";
    std::cout << "1. Convert String to Double\n2. Exit\n";
}

bool handleChoice(unsigned short choice) {
    if (choice == 1)
    {
        std::string input;
        std::cout << "Enter string: ";
        std::getline(std::cin, input);

        double result = atof(input);
        std::cout << "Output: " << result << "\n";
    }
    else if (choice == 2)
    {
        std::cout << "Exiting Program...\n";
        return true;
    }
    else
    {
        std::cout << "Invalid Choice! Enter again: ";
    }

    return false;
}

int main() {
    while (true)
    {
        printMenu();

        std::cout << "\nEnter your choice: ";
        unsigned short choice = getChoice();

        bool shouldExit = handleChoice(choice);

        if (shouldExit)
        {
            return 0;
        }
    }


    
}