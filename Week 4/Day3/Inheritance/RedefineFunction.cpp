#include <iostream>

class Base {
public:
    void identify() {
        std::cout << "Base->identify\n";
    }
};

class Derived : public Base {
public:
    void identify() {
        std::cout << "Derived->identify\n";
        Base::identify(); //To call base identify
        // identify(); --> self call and infinite recursion
    }
};

int main() {
    Derived derived;

    //Access its own function 
    derived.identify(); 
}