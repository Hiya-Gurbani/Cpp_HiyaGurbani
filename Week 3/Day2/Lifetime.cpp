//The lifetime of references and referents are independent
#include <iostream>

int main() {
    int x = 23;

    {
        int& ref = x;
        std::cout << ref << "\n";
    } //Ref is destroyed here
    // std::cout << ref << "\n";

    std::cout << x << "\n";
} //X is destroyed here