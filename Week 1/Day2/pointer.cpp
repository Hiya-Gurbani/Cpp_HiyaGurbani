#include <iostream>

int main() {
    int number = 10;
    int *ptr = &number;

    std::cout << "Address of number: " << &number << "\n";
    std::cout << "Value of ptr: " << ptr << "\n";
    std::cout << "Value stored at ptr: " << *ptr << "\n";
}