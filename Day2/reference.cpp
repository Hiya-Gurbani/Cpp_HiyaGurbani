#include <iostream>

int main() {
    int number = 10;
    int& reference = number;

    std::cout << "Value of number: " << number << "\n";
    std::cout << "Value of reference: " << reference << "\n";

    reference = 20;
    std::cout << "After Update: " << "\n";
    std::cout << "Value of number: " << number << "\n";
    std::cout << "Value of reference: " << reference << "\n";
}