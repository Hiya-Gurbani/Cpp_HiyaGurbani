#include <iostream>

void displayDiamond(int range) {
    for (int rowIndex = 0; rowIndex < range; rowIndex++)
    {
        for (int colIndex = 0; colIndex < range - rowIndex; colIndex++)
        {
            std::cout << " ";
        }
        for (int colIndex = 0; colIndex <= rowIndex; colIndex++)
        {
            std::cout << "*";
        }
        for (int colIndex = 1; colIndex <= rowIndex; colIndex++)
        {
            std::cout << "*";
        }
        for (int colIndex = 0; colIndex < range - rowIndex; colIndex++)
        {
            std::cout << " ";
        }
        std::cout << "\n";
    }

    for (int rowIndex = 1; rowIndex < range; rowIndex++)
    {
        for (int colIndex = 0; colIndex <= rowIndex; colIndex++)
        {
            std::cout << " ";
        }
        for (int colIndex = 0; colIndex < range - rowIndex; colIndex++)
        {
            std::cout << "*";
        }
        for (int colIndex = 1; colIndex < range - rowIndex; colIndex++)
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }
}

int main() {
    int range;
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> range;

    displayDiamond(range);
}