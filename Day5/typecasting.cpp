#include <iostream>

int main() {
    //Implicit Typecasting
    int value1 = 3;
    double value2 = 4.5;

    std::cout << "Implicit Typecasting (int to double): " << value1 + value2 << "\n";

    int result = value1 + value2;
    std::cout << "Implicit Typecasting (double to int): " << result << "\n";

    //Explicit Typecasting
    double value3 = 9.75;
    int value4 = (int)value3;
    std::cout << "Explicit Typcasting: " << value4 << "\n";

    double value5 = 9.67;
    int value6 = static_cast<int> (value5);
    std::cout << "Explicit Typcasting: " << value6 << "\n";

}