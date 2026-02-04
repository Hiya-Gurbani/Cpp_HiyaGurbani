#include <iostream>

class Base {
public:
    void identify() {
        std::cout << "Base->identify\n";
    }
};

class Derived : public Base {
public:
    using Base::identify;

    void identify() {
        std::cout << "Derived->identify\n";
    }
};

int main() {
    Derived derived;
    derived.identify(); 
}