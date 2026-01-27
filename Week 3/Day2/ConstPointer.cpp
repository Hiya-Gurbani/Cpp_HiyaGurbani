#include <iostream>

int main()
{
    int value1 = 5;
    int* const ptr1 = &value1;

    // int* const ptr2; //Compiler Error : Uninitialised 

    int* const ptr3 = nullptr;
    // std::cout << *ptr3 << "\n"; //Segmnetation fault UB

    return 0;
}