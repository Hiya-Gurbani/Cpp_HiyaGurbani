#include <iostream>

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

bool handleCharacter(char character, double& value, double& decimalFactor, bool& isDecimal) {
    if (character >= '0' && character <= '9')
    {
        handleDigit(value, decimalFactor, isDecimal, character - '0');
    }
    else if (character == '.')
    {
        if (isDecimal)
        {
            return false;
        }
        isDecimal = true;
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
        if (!handleCharacter(input[index], value, decimalFactor, isDecimal))
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