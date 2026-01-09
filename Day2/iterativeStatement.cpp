#include <iostream>

//Program to find sum of n numbers and countdown to 0

int main() {
    int number;
    std::cin >> number;

    int sum = 0;
    for (int currentNumber = 0; currentNumber <= number; currentNumber++)
    {
        sum += currentNumber;
    }

    std::cout << "Sum: " << sum << "\n";

    if (number > 0)
    {
        while (number != 0)
        {
            std::cout << number-- << " ";
        }
    }
    else
    {
        while (number != 0)
        {
            std::cout << number++ << " ";
        }
    }
}