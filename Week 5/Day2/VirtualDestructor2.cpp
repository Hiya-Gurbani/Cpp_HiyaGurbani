#include <iostream>

class Base {
public:
    //If Base doens't need a explicit Destructor still we need 
    //create virtual one so Derived's destructors are called
    //Default Constructors are non-virtual by def
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived Destructor\n";
    }
};

class Derived2 :public Derived {
public:
    ~Derived2() {
        std::cout << "Derived2 Destructor\n";
    }
};

int main() {
    Base* b = new Derived;

    //Without virtual only calls B's destructor
    delete b;

    Base* b2 = new Derived2;
    delete b2;
}