#include <iostream>

inline int getSum(int value1, int value2) {
    return value1 + value2;
}

int main() {
    int value1, value2;
    std::cout << "Enter two space-seperated values: ";
    std::cin >> value1 >> value2;

    std::cout << "The sum is: " << getSum(value1, value2)<< "\n";
}