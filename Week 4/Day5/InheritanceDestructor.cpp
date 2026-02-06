#include <iostream>

class Base {
public:
    Base() { 
        std::cout << "Base constructor\n"; 
    }
    ~Base() { 
        std::cout << "Base destructor\n"; 
    }
};

class Derived : public Base {
public:
    Derived() { 
        std::cout << "Derived constructor\n"; 
    }

    ~Derived() {
        //We call it once and c++ runtime calls it later again
        //Would cause Undefined Behavior or issue if have new or delete
        Base::~Base(); 
        std::cout << "Derived destructor\n";
        std::cout << "Manually calling Base destructor!\n";
    }
};

int main() {
    Derived d;
}
