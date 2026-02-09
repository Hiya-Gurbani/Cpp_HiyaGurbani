#include <iostream>
#include <string>

class Base {
public:
    virtual std::string getName() {
        return "Base";
    }
};

class Derived1 : public Base {
public:
    std::string getName() {
        return "Derived 1";
    }
};

class Derived2 : public Base {
public:
    std::string getName() {
        return "Derived 2";
    }
};

int main() {
    Derived1 derived1;
    Base& rBase1 = derived1;

    //Only function from Base to Derived1 are considered
    std::cout << "derived calls " << derived1.getName();
    std::cout << "\nrBase calls " << rBase1.getName() << "\n";

    Derived2 derived2;
    Base& rBase2 = derived2;

    //Works even when I didn't worte Derived1 fucntion as virtual
    //All matrching overrides are implicitly virtual
    std::cout << "\nderived calls " << derived2.getName();
    std::cout << "\nrBase calls " << rBase2.getName() << "\n";


    //Without pointers even virtual won't work
    Base base1 = derived1;
    std::cout << "\nBase1 calls " << base1.getName() << "\n";
    Base base2 = derived2;
    std::cout << "Base2 calls " << base2.getName() << "\n";
}