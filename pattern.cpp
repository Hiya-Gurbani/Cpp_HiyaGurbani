#include <iostream>
#include <climits>
#include <string>

#define MIN_CHOICE 1
#define MAX_CHOICE 2

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

bool isValidInteger(const std::string& input, const size_t start, const size_t end, int& choice) {
    choice = 0;

    for (size_t index = start; index < end; ++index)
    {
        if (input[index] >= '0' && input[index] <= '9')
        {
            int digit = input[index] - '0';
            
            if (choice > (INT_MAX - digit) / 10)
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
    int choice {0};

    while (true) {
        std::getline(std::cin, input);

        size_t start = 0;
        size_t end = input.size();

        removeWhitespace(input, start, end);
        if (start == end)
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

bool isValidLongLong(const std::string& input, const size_t start, const size_t end, long long& value) {
    value = 0;

    for (size_t index = start; index < end; ++index)
    {
        if (input[index] >= '0' && input[index] <= '9')
        {
            int digit = input[index] - '0';
            
            if (value > (LLONG_MAX - digit) / 10)
            {
                return false;
            }
            value = (value * 10) + digit;
        }
        else
        {
            return false;
        }
    }
    return true;
}

long long getValue() {
    std::string input;
    long long value {0};

    while (true) {
        std::getline(std::cin, input);

        size_t start = 0;
        size_t end = input.size();

        removeWhitespace(input, start, end);
        if (start == end)
        {
            std::cout << "Empty Input! Enter again: ";
            continue;
        }

        if (!isValidLongLong(input, start, end, value))
        {
            std::cout << "Invalid Input! Enter again: ";
            continue;
        }

        return value;
    }

    return value;
}

void displayPattern(long long number) {
    bool flag = false;
    if (number % 2 == 0) flag = true;

    for (long long rowIndex = 0; rowIndex <= number; rowIndex++) {
        int digit = 1;
        for (long long colIndex = 0; colIndex <= rowIndex; colIndex++)
        {
            std::cout << digit;
            digit = (digit == 1) ? 0 : 1; 
        }

        for (long long colIndex = 0; colIndex < number - rowIndex; colIndex++)
        {
            std::cout << " ";
        }

        long long colIndex = 0;
        if (flag)
        {
            colIndex = 1;
        }
        for (; colIndex < number - rowIndex; colIndex++)
        {
            std::cout << " ";
        }

        digit = 1;
        for (long long colIndex = 0; colIndex <= rowIndex; colIndex++)
        {
            if (!flag || rowIndex != number || colIndex != 0)
                std::cout << digit;
            digit = (digit == 1) ? 0 : 1;
        }

        std::cout << "\n";
    }

    for (long long rowIndex = 0; rowIndex < number; rowIndex++) {
        int digit = 1;
        for (long long colIndex = 0; colIndex < number - rowIndex; colIndex++)
        {
            std::cout << digit;
            digit = (digit == 1) ? 0 : 1; 
        }

        for (long long colIndex = 0; colIndex <= rowIndex; colIndex++)
        {
            std::cout << " ";
        }

        long long colIndex = 0;
        if (flag)
        {
            colIndex = 1;
        }
        for (; colIndex <= rowIndex; colIndex++)
        {
            std::cout << " ";
        }

        digit = 1;
        for (long long colIndex = 0; colIndex < number - rowIndex; colIndex++)
        {
            std::cout << digit;
            digit = (digit == 1) ? 0 : 1;
        }

        std::cout << "\n";
    }
}

void printMenu() {
    std::cout << "\nOperations:";
    std::cout << "\n1. Print Pattern\n2. Exit\n";
    std::cout << "\nEnter your choice: ";
}

bool handleChoice(const int choice) {
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
        std::cout << "Invalid Choice.\n";
    }

    return false;
}

int main() {
    while (true) {
        printMenu();
        int choice = getChoice();

        bool shouldExit = handleChoice(choice);

        if (shouldExit)
        {
            return 0;
        }
    }

    return 0;
}