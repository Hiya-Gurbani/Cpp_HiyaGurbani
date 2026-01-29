#include <iostream>

int* getPointer() {
    int x = 100;

    //Warning: (Compiler Error) address of local variable returned
    return &x;
}

int main() {
    int* ptr = getPointer();
    std::cout << ptr << "\n";
    std::cout << *ptr << "\n";
}