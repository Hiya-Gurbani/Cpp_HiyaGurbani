#include <iostream>

int main() {
    int value1 = 1;
    std::cout << value1 << " " << sizeof(value1) << std::endl;

    float value2 = 1.01f;
    float value6 = 1.01; //Treated as double by def and converted to float
    std::cout << value2 << " " << sizeof(value2) << std::endl;

    double value3 = 1.01;
    std::cout << value3 << " " << sizeof(value3) << std::endl;

    bool value4 = true;
    std::cout << value4 << " " << sizeof(value4) << std::endl;

    char value5 = 'h';
    std::cout << value5 << " " << sizeof(value5) << std::endl;

    //void value5; -- Invalid (variable or field declared void)
}