#include <iostream>

int main() {
    int value = 10;
    int* pointer = &value;

    std::cout << "Size of Int: " << sizeof(int) << "\n";
    std::cout << "Address of variable: " << pointer << "\n";

    pointer--;
    std::cout << "After decrementing variable: " << pointer << "\n";

    pointer++;
    std::cout << "After incrementing variable: " << pointer << "\n";
}