#include <iostream>

class Base {
public:
    virtual Base* getClass() {
        std::cout << "Returning Base Class\n";
        return this;
    }
    void printType() { 
        std::cout << "returned a Base\n"; 
    }
};

class Derived : public Base {
public:
    Derived* getClass() {
        std::cout << "Returning Base Class\n";
        return this;
    }
    void printType() { 
        std::cout << "returned a Derived\n"; 
    }
};

int main() {
    Derived d;
    d.getClass()->printType();

    //The base function is still overiidden w/o matching returns
    Base* b = &d;
    b->getClass()->printType();
}