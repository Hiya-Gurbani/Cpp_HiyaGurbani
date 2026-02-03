#include <iostream>
#include <array>
#include <span>

//Best way to pass array by reference
void function1(int (&array)[5]);

//Use std::array instead
void function2(const std::array<int, 5>& array);

//Doesn't stop the decay, just helps handling it properly
void function3(const int* array, size_t size);

//Similar to above just bundled nicely in C++ 20+
// void function4(std::span<int> array);

int main() {
    int array[] = {1, 2, 3, 4, 5};
}