#include <iostream>

int main() {
    int num1 = 5;
    // int& num2; Error: Refrence must be initialised
    int numRef = num1; 
    
    std::cout << num1 << numRef << '\n';

    num1 = 6; 

    std::cout << num1 << numRef << '\n'; // prints 66

    numRef = 7; 

    std::cout << num1 << numRef << '\n'; // prints 77

    return 0;
}