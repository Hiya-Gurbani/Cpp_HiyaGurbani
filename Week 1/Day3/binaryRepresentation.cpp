#include <iostream>

void printBinary(int number) {
    if (number == 0)
    {
        return;
    }

    printBinary(number / 2);

    std::cout << number % 2;
}

int main() {
    int number;
    std::cin >> number;

    printBinary(number);
}