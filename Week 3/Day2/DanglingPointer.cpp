#include <iostream>

int main() {
    int value = 10;
    int* ptr;

    //Undefined Behavior: as ptr is Wild -- Segmentation fault here
    // std::cout << *ptr << "\n"; 

    ptr = &value;

    std::cout << *ptr << "\n";

    {
        int newValue = 20;
        ptr = &newValue;

        std::cout << *ptr << "\n";
    }

    std::cout << *ptr << "\n"; //Undefined Behavior: as ptr is dangling
}