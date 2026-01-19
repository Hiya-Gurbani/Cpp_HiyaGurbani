#include <iostream>
#include <climits>
#include <string>

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
                    size_t end, unsigned short& choice) {

    for (size_t index = start; index < end; ++index)
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

bool isValidLongLong(const std::string& input, size_t start, 
                     size_t end, long long& value) {

    for (size_t index = start; index < end; ++index)
    {
        if (input[index] >= '0' && input[index] <= '9')
        {
            int digit = input[index] - '0';
            
            if (value > (LLONG_MAX - digit) / 10)
            {
                std::cout << "Invalid Input! The entered number is too long. Enter again: ";
                return false;
            }
            value = (value * 10) + digit;
        }
        else
        {
            std::cout << "Invalid Input! Only digits allowed. Enter again: ";
            return false;
        }
    }

    return true;
}

long long getValue() {
    std::string input;
    long long value {0};

    bool isValidValue = true;

    while (true) {
        isValidValue = true;
        value = 0;
        std::getline(std::cin, input);

        size_t start = 0;
        size_t end = input.size();

        removeWhitespace(input, start, end);
        if (start == end)
        {
            std::cout << "Empty Input! Kindly enter a value: ";
            isValidValue = false;
        }
        else if (!isValidLongLong(input, start, end, value))
        {
            isValidValue = false;
        }

        if (!isValidValue)
        {
            continue;
        }

        return value;
    }

    return value;
}

void printAlternateDigits(long long startIndex, long long endIndex) {
    unsigned short digit = 1;
    for (long long colIndex = startIndex; colIndex < endIndex; colIndex++)
    {
        std::cout << digit;
        digit = (digit == 1) ? 0 : 1; 
    }
}

void printSpaces(long long startIndex, long long endIndex) {
    for (long long colIndex = startIndex; colIndex < endIndex; colIndex++)
    {
        std::cout << " ";
    }
}

void printTopLastDigits(long long range, long long rowIndex, bool isEven) {
    unsigned short digit = 1;
    for (long long colIndex = 0; colIndex <= rowIndex; colIndex++)
    {
        if (isEven && rowIndex == range && colIndex == 0)
        {
            digit = (digit == 1) ? 0 : 1;
            continue;
        }
            
        std::cout << digit;
        digit = (digit == 1) ? 0 : 1;
    }
}

void displayPatternTop(long long range, bool isEven) {
    for (long long rowIndex = 0; rowIndex <= range; rowIndex++) {
        printAlternateDigits(0, rowIndex + 1);

        printSpaces(0, range - rowIndex);

        printSpaces(isEven ? 1 : 0, range - rowIndex);

        printTopLastDigits(range, rowIndex, isEven);

        std::cout << "\n";
    }
}

void displayPatternBottom(long long range, bool isEven) {
    for (long long rowIndex = 0; rowIndex < range; rowIndex++) {
        printAlternateDigits(0, range - rowIndex);

        printSpaces(0, rowIndex + 1);

        printSpaces(isEven ? 1 : 0, rowIndex + 1);

        printAlternateDigits(0, range - rowIndex);

        std::cout << "\n";
    }
}

void displayPattern(long long range) {
    bool isEven = (range % 2 == 0);

    displayPatternTop(range, isEven);
    displayPatternBottom(range, isEven);
}

void printMenu() {
    std::cout << "\nOperations:\n";
    std::cout << "1. Print Pattern\n2. Exit\n";
}

bool handleChoice(unsigned short choice) {
    if (choice == 1)
    {
        std::cout << "Enter value: ";
        long long value = getValue();
        displayPattern(value);
    }
    else if (choice == 2)
    {
        std::cout << "Exiting Program...\n";
        return true;
    }
    else
    {
        std::cout << "Invalid Choice. Enter again: \n";
    }

    return false;
}

int main() {
    while (true) {
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