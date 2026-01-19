#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <cctype>

void removeWhitespace(const std::string& input, size_t& start, size_t& end) {
    while (start < end && input[start] == ' ')
    {
        start++;
    }

    while (end > start && input[end - 1] == ' ')
    {
        end--;
    }
}

bool isValidInteger(const std::string& input, size_t start, 
                    size_t end, unsigned short& choice ) {

    for (size_t index = start; index < end; index++)
    {
        if (input[index] >= '0' && input[index] <= '9')
        {
            int digit = input[index] - '0';
            if (choice > (USHRT_MAX - digit) / 10)
            {
                std::cout << "Invalid Input! The entered choice is too long. Enter again: ";
                return false;
            }
            choice = (choice * 10) + digit;
        }
        else
        {
            std::cout << "Invalid Input! Only digits allowed. Enter again: ";
            return false;
        }
    }

    return true;
}

int getChoice() {
    std::string input;
    unsigned short choice = 0;

    bool isValidChoice = true;

    constexpr int MIN_CHOICE = 1;
    constexpr int MAX_CHOICE = 2;

    while (true) {
        isValidChoice = true;
        choice = 0;
        std::getline(std::cin, input);

        size_t start = 0;
        size_t end = input.size();

        removeWhitespace(input, start, end);
        if (start >= end)
        {
            std::cout << "Empty Input! Kindly enter a value: ";
            isValidChoice = false;
        }
        else if (!isValidInteger(input, start, end, choice))
        {
            isValidChoice = false;
        }
        else if (choice < MIN_CHOICE || choice > MAX_CHOICE)
        {
            std::cout << "Invalid Choice! Choice must be 1 or 2. Enter again: ";
            isValidChoice = false;
        }

        if (!isValidChoice)
        {
            continue;
        }

        return choice;
    }

    return choice;
}

int getSign(char character, size_t& index) {
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

double handleSpecialCase(std::string& inputSubstring, int sign, double& value) {
    for (auto& character : inputSubstring)
    {
        character = std::tolower(static_cast<unsigned char>(character));
    }

    if (inputSubstring == "inf")
    {
        value = sign * std::numeric_limits<double>::infinity();
    }
    else if (inputSubstring == "nan")
    {
        value = sign * std::numeric_limits<double>::quiet_NaN();
    }

    return value;
}

bool isHexadecimalNumber(const std::string& input, size_t& start, 
                         size_t end, double& decimalFactor) {

    constexpr int HEX_BASE = 16;

    if (start + 1 < end && input[start] == '0' && 
    (input[start + 1] == 'x' || input[start + 1] == 'X'))
    {
        start += 2;
        decimalFactor = 1.0 / HEX_BASE;
        return true;
    }

    return false;
}

void handleDigit(double& value, double& decimalFactor, bool isDecimal, int digit) {
    constexpr int DECIMAL_BASE = 10;

    if (!isDecimal)
    {
        value = (value * DECIMAL_BASE) + digit;
    }
    else
    {
        value += digit * decimalFactor;
        decimalFactor /= DECIMAL_BASE;
    }
}

int getDigitValue(char character) {
    constexpr int DECIMAL_BASE = 10;

    if (character >= '0' && character <= '9')
    {
        return (character - '0');
    }
    else 
    {
        return 
        ((std::tolower(static_cast<unsigned char> (character)) - 'a') + DECIMAL_BASE);
    }

    return 0;
}

void handleHexadecimalDigit(double& value, double& decimalFactor, 
                            bool isDecimal, char character) {

    constexpr int HEX_BASE = 16;
    int digit = getDigitValue(character);

    if (!isDecimal)
    {
        value = (value * HEX_BASE) + digit;
    }
    else
    {
        value += (digit * decimalFactor);
        decimalFactor /= HEX_BASE;
    }
}

int getExponentValue(const std::string& input, size_t& index) {
    constexpr int DECIMAL_BASE = 10;
    int exponentValue = 0;

    while (index < input.size() && input[index] >= '0' && input[index] <= '9')
    {
        exponentValue = (exponentValue * DECIMAL_BASE) + (input[index] - '0');
        index++;
    }

    return exponentValue;
}

void handleExponent(const std::string& input, size_t& index, 
                    bool isHexadecimal, double& value) {

    constexpr int DECIMAL_EXPONENT_BASE = 10;
    constexpr int HEX_EXPONENT_BASE = 2;

    index++;
    if (index >= input.size())
    {
        return;
    }

    int exponentSign = getSign(input[index], index);
    int exponentValue = getExponentValue(input, index);

    int exponentBase = (isHexadecimal? HEX_EXPONENT_BASE : DECIMAL_EXPONENT_BASE); 
    value *= pow(exponentBase, exponentSign * exponentValue);
}

bool handleCharacter(const std::string& input, size_t& index, double& value, 
                    double& decimalFactor, bool& isDecimal, bool& isHexadecimal) {

    bool continueParsing = true;

    if (!isHexadecimal && input[index] >= '0' && input[index] <= '9')
    {
        handleDigit(value, decimalFactor, isDecimal, input[index] - '0');
    }
    else if (isHexadecimal && std::isxdigit(static_cast<unsigned char> (input[index])))
    {
        handleHexadecimalDigit(value, decimalFactor, isDecimal, input[index]);
    }
    else if (input[index] == '.')
    {
        if (isDecimal)
        {
            return false;
            continueParsing = false;
        }
        isDecimal = true;
    }
    else if (!isHexadecimal && (input[index] == 'e' || input[index] == 'E'))
    {
        handleExponent(input, index, isHexadecimal, value);
        continueParsing = false;
    }
    else if (isHexadecimal && (input[index] == 'p' || input[index] == 'P'))
    {
        handleExponent(input, index, isHexadecimal, value);
        continueParsing = false;
    }
    else
    {
        continueParsing = false;
    }

    return continueParsing;
}

double stringToDouble(const std::string& input) {
    double value = 0;
    size_t start = 0;
    size_t end = input.size();

    removeWhitespace(input, start, end);
    if (start >= end)
    {
        return value;
    }

    double decimalFactor = 0.1;
    bool isDecimal = false;

    int sign = getSign(input[start], start);
    bool isHexadecimal = isHexadecimalNumber(input, start, end, decimalFactor);

    std::string inputSubstring = input.substr(start, 3);
    if (handleSpecialCase(inputSubstring, sign, value) != 0)
    {
        return value;
    }
    
    for (size_t index = start; index < end; index++)
    {
        if (!handleCharacter(input, index, value, decimalFactor, isDecimal, isHexadecimal))
        {
            break;
        }
    }

    if (value == 0 && sign == -1)
    {
        return 0;
    }
    return (value * sign);
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

        double result = stringToDouble(input);
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

    return 0;
}