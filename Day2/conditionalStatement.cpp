#include <iostream>

//Check a number is positive, negative or 0
// If positive check for even & odd

int main() {
    int value;
    std::cin >> value;

    if (value > 0)
    {
        if (value % 2 == 0)
        {
            std::cout << "Positive & Even";
        }
        else
        {
            std::cout << "Positive & Odd";
        }
    }

    else if (value < 0)
    {
        std::cout << "Negative";
    }

    else
    {
        std::cout << "Zero";
    }
}