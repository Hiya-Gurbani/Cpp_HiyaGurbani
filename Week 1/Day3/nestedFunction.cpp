#include <iostream>

int main() {
    //Error : Function Definition Not Allowed
    void nestedFunction() {
        std::cout << "Nested Function";
    }

    nestedFunction(); //Error: Not declared in scope
}