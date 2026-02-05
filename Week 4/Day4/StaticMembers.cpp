#include <iostream>

class Practise {
    static int value4; 
public:
    static int value; 
    static int value1;

    //Error: C++ forbids in-class initialization of non-const static member
    // static int value = 1; 

    //Const and inline def is allowed
    static const int value2 = 5;
    static inline int value3 = 10;
};

int Practise::value; //Need to define value as well else error
int Practise::value1 = 10;

int main() {
    Practise p;

    std::cout << p.value << "\n";
    std::cout << p.value1 << "\n";
    std::cout << p.value2 << "\n";
    std::cout << p.value3 << "\n";
    //Can't access it as it is private
    // std::cout << p.value4 << "\n";
}