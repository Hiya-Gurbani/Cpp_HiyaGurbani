#include <iostream>

#define MIN_CHOICE 1
#define MAX_CHOICE 2

int getChoice() {
    std::string input;
    int choice {0};

    while (true) {
        std::getline(std::cin, input);

        size_t start = 0;
        while (start < input.size() && input[start] == ' ')
        {
            start++;
        }

        size_t end = input.size();
        while (end > start && input[end - 1] == ' ')
        {
            end--;
        }

        if (start == end)
        {
            std::cout << "Invalid Input! Enter again: ";
            continue;
        }

        bool isValid = true;
        choice = 0;
        for (size_t index = start; index < end; ++index)
        {
            if (input[index] >= '0' && input[index] <= '9')
            {
                choice =  (choice * 10) + (input[index] - '0');
            }
            else
            {
                isValid = false;
                break;
            }
        }

        if (!isValid)
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

long long getValue() {
    std::string input;
    long long value {0};

    while (true) {
        std::getline(std::cin, input);

        size_t start = 0;
        while (start < input.size() && input[start] == ' ')
        {
            start++;
        }

        size_t end = input.size();
        while (end > start && input[end - 1] == ' ')
        {
            end--;
        }

        if (start == end)
        {
            std::cout << "Invalid Input! Enter again: ";
            continue;
        }

        bool isValid = true;
        value = 0;
        for (size_t index = start; index < end; ++index)
        {
            if (input[index] >= '0' && input[index] <= '9')
            {
                value =  (value * 10) + (input[index] - '0');
            }
            else
            {
                isValid = false;
                break;
            }
        }

        if (!isValid)
        {
            std::cout << "Invalid Value! Enter again: ";
            continue;
        }

        return value;
    }

    return value;
}

void pattern(long long number) {
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

int main() {
    while (true) {
        std::cout << "\nOperations:";
        std::cout << "\n1. Print Pattern\n2. Exit\n";
        std::cout << "\nEnter your choice: ";
        int choice = getChoice();

        if (choice == 1)
        {
            std::cout << "Enter value: ";
            long long value = getValue();
            pattern(value);
        }
        else if (choice == 2)
        {
            std::cout << "Exiting Program...\n";
            return 0;
        }
    }
    return 0;
}