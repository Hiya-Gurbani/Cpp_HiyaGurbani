#include <iostream>
//Adding and subtracting constant from pointer
//Formula: base address + (value of constant * sizeof(type))

int main() {
    int value = 10;
    int* pointer = &value;

    std::cout << "Address holded by pointer: " << pointer << "\n";
    pointer += 2;

    //Address increased by 8bytes
    std::cout << "Address holded after increment: " << pointer << "\n";


    //Second Pointer: Subtraction
    double value2 = 10;
    double* pointer2 = &value2;

    std::cout << "Size of double: " << sizeof(double) << "\n";
    std::cout << "Address holded by pointer: " << pointer2 << "\n";
    pointer2 -= 2;

    //Address decreased by 16 bytes
    std::cout << "Address holded after decrement: " << pointer2 << "\n";
}