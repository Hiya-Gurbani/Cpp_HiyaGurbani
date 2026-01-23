#include <iostream>

void callPrint() {
    std::cout << "Hey";
}

void printNumber(int number) {
    std::cout << number;
}

int main() {
    //Compiler see the mention of function so no error but doesn't call it too
    callPrint; //It is like a reference to the function

    printNumber; //No error treated as mention
    //printNumber(); //Error: Two few arguments
    printNumber(10); //Right Call
}