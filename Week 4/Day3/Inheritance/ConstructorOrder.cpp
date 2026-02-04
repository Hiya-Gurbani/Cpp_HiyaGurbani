#include <iostream>

class Base {
    int id;
public:
    Base() {
        std::cout << "Base Constructor Called\n";
    }
    ~Base() {
        std::cout << "Base Destructor Called\n";
    }
};

class Derived : public Base {
    int id;
public:
    Derived() {
        std::cout << "Derived Constructor Called\n";
    }
    ~Derived() {
        std::cout << "Derived Destructor Called\n";
    }
};

int main() {
    Derived d;
    std::cout << sizeof(d) << "\n"; //8 bytes
}