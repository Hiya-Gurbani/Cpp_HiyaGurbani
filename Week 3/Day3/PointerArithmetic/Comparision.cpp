#include <iostream>

int main() {
    int value = 10;
    int* pointer1 = &value;
    int** pointer2 = &pointer1;
    int* pointer3 = *pointer2;

    std::cout << *pointer1 << "\n";
    std::cout << pointer1 << "\n";
    std::cout << *pointer2 << "\n";
    std::cout << **pointer2 << "\n";

    if (pointer3 == pointer1)
    {
        std::cout << "Both hold the same value!\n";
    }
}