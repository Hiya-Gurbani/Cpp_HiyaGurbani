#include <iostream>

int sumOfDigits(int number) {
    if(number == 0)
    {
        return 0;
    }

    return sumOfDigits(number / 10) + (number % 10);
}

int main() {
    int number;
    std::cin >> number;

    std::cout << sumOfDigits(number);
}