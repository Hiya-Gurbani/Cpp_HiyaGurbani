#include <iostream>

void oneToN(int number) {
    if (number == 0)
    {
        return;
    }

    oneToN(number - 1);
    std::cout << number << "\n";
}

void nToOne(int number) {
    if (number == 0)
    {
        return;
    }

    std::cout << number << "\n";
    nToOne(number - 1);
}

int main() {
    int number;
    std::cin >> number;

    oneToN(number);
    nToOne(number);
}