#include <iostream>

int returnNumber() {
    return 5;
}

void printNumber() {
    std::cout << 5;
}

int main() {
    std::cout << returnNumber() << "\n";
    //std::cout << printNumber() << "\n"; //Error as printNumber returns nothing;
    std::cout << printNumber; //Prints true as the function exist
    std::cout << printSum; //Error as printSum doesn't exist
}