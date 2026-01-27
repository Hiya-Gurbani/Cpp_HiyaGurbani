#include <iostream>

int main() {
    int num1 = 10;
    int num2 = 20;

    int* ptr = &num1;
    std::cout << *ptr << "\n";

    //Changed what ptr is pointing at
    ptr = &num2;
    std::cout << *ptr << "\n";

    //Changed the value being pointed at
    *ptr = 30;
    std::cout << *ptr << "\n";

    std::cout << num1 << " " << num2 << "\n";
}