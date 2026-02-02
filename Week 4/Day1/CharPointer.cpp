#include <iostream>

int main() {
    char ch1 = 'c';
    char* ptr1 = &ch1;

    //Might have ? because means too huge address or some invalid symbols
    std::cout << &ptr1 << "\n"; 
    std::cout << *ptr1 << "\n";

    char ch2[] = "c";
    char* ptr2 = ch2;

    std::cout << &ptr2 << "\n";
    std::cout << *ptr2 << "\n";
}