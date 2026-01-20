#include "add.h"
#include <iostream>

int main() {
    int value1, value2;

    std::cout << "Enter two values: ";
    std::cin >> value1 >> value2;

    std::cout << "Result: " << add(value1, value2);
}