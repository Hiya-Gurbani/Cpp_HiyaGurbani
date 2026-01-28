#include <iostream>

int add(int num1, int num2) {
    return num1 + num2;
}

int increment(int num1) {
    return num1 + 1;
}

int main() {
    int (*ptr)(int, int);
    ptr = &add;
    // ptr = add; //Same

    int (*ptr2)(int);
    ptr2 = increment;

    int result = (*ptr)(5, 3); //Explicit Dereference
    std::cout << result << "\n";

    int result2 = ptr(5,3); //Implicit Dereference
}