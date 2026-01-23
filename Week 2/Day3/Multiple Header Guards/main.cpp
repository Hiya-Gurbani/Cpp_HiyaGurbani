#include "math.h"

int main() {
    int value1, value2;
    std::cout << "Enter two space-seperated integers: ";
    std::cin >> value1 >> value2;

    std::cout << "Addition is: " << add(value1, value2) << "\n";
    std::cout << "Subtraction is: " << subtract(value1, value2) << "\n";
}