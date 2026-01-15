#include <iostream>
#include <string>
#include <cmath>

void removeWhitespace(const std::string input, size_t& start, size_t end) {
    while (start < input.size() && input[start] == ' ')
    {
        start++;
    }

    while (end > start && input[end - 1] == ' ')
    {
        end--;
    }
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

int getExponentSign(char character, int& index) {
    if (character == '-')
    {
        index++;
        return -1; 
    }
    else if (character == '+')
    {
        index++;
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

void handleExponent(const std::string& input, int& index, double& value) {
    index++;
    if (index >= input.size())
    {
        return;
    }

    int exponentSign = getExponentSign(input[index], index);
    int exponentValue = getExponentValue(input, index);

    value *= pow(10, exponentSign * exponentValue);
}

bool handleCharacter(std::string& input, int& index, double& value, 
                    double& decimalFactor, bool& isDecimal) {
    if (input[index] >= '0' && input[index] <= '9')
    {
        handleDigit(value, decimalFactor, isDecimal, input[index] - '0');
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
        handleExponent(input, index, value);
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
    if (start > end)
    {
        return value;
    }

    bool isPositive = isPositiveNumber(input[start], start);
    
    double decimalFactor = 0.1;
    bool isDecimal = false;
    
    for (int index = start; index < end; index++)
    {
        if (!handleCharacter(input, index, value, decimalFactor, isDecimal))
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

int main() {
    std::string input;
    std::getline(std::cin, input);

    double result = atof(input);

    std::cout << result << "\n";
}