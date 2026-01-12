#include <iostream>

void pattern1(int number) {
    for (int rowIndex = 0; rowIndex < number; rowIndex++)
    {
        int numberToPrint = 1;
        for (int colIndex = 0; colIndex <= rowIndex; colIndex++)
        {
            std::cout << numberToPrint << " ";
            numberToPrint = (numberToPrint == 1) ? 0 : 1;
        }

        for (int colIndex = rowIndex + 1; colIndex < number; colIndex++)
        {
            std::cout << " ";
        }
        std::cout << "\n";
    }
}

void pattern2(int number) {
    for (int rowIndex = 0; rowIndex < number; rowIndex++)
    {
        int numberToPrint = 1;
        for (int colIndex = 0; colIndex < number - rowIndex; colIndex++)
        {
            std::cout << "  ";
        }

        for (int colIndex = number - rowIndex - 1; colIndex < number; colIndex++)
        {
            std::cout << numberToPrint << " ";
            numberToPrint = (numberToPrint == 1) ? 0 : 1;
        }

        std::cout << "\n";
    }
}

int main() {
    int number {};

    std::cout << "Enter the number of rows and columns: ";
    std::cin >> number;

    pattern1(number/2 + 1);
    pattern2(number/2 + 1);
}