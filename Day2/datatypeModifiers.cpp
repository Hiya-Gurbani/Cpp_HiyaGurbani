#include <iostream>

int main() {
    //long can be used with int & double
    //short and long long only with int

    int value1 = 1;
    std::cout << sizeof(value1) << "\n";

    short int value2 = 1;
    std::cout << sizeof(value2) << "\n";

    long int value3 = 1;
    std::cout << sizeof(value3) << "\n";

    long long int value4 = 1;
    std::cout << sizeof(value4) << "\n";

    long double value5 = 1.01;
    std::cout << sizeof(value5) << "\n";

    short int value6 = 1;
    std::cout << sizeof(value6) << "\n";

}