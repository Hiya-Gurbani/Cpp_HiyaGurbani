#include <iostream>
#include <string>

class Base {
protected:
    int value;

public:
    Base(int givenValue) 
    : value {givenValue} {
    }
    std::string getName() { 
        return "Base"; 
    }
    int getValue() {
        return value; 
    }
};


class Derived : public Base {
public:
    Derived(int givenValue)
    : Base {givenValue} {
    }
    std::string getName() { 
        return "Derived"; 
    }
    int getValue() {
        return value; 
    }
    int display() {}
};

int main() {
    Derived derived(5);
    std::cout << "derived is a " << derived.getName() << " and has value "
    << derived.getValue() << '\n';

    Base& rBase(derived);
    std::cout << "rBase is a " << rBase.getName() << " and has value " 
    << rBase.getValue() << '\n';

    Base* pBase(&derived);
    std::cout << "pBase is a " << pBase->getName() << " and has value " 
    << pBase->getValue() << '\n';

    derived.display();
    // Error: No function name dispaly as they can only see member of Base
    // rBase.display();
    // pBase->display();
}