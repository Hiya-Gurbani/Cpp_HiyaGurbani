#include <iostream>

int main() {
    int num1 = 5; //5 is rvalue exp
    const double value1 = 10.0; //10.0 is also rvalue exp

    int num2 = num1; //num1 Modifiable lvalue exp
    double value2 = value1; //value1 Non Modifiable lvalue


    int num3 = num1 + 2; //num1 + 2 is also rvalue

}