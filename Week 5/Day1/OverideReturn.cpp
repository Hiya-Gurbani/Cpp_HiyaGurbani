#include <iostream>
#include <string>

class Base {
protected:
    int value;
public:
    virtual std::string getName() {
        return "Base";
    }
    virtual int getValue(int num) {
        return value;
    }
};

class Derived : public Base {
public:
    std::string getName() {
        return "Derived";
    }
    //Conflicting return type
    // void getValue() {
    //     return;
    // }

    //No overriding
    void getValue(int& num) {
        num = value;
    }

    //No overriding
    int getValue(double num) {

    }
};

int main() {
    Derived derived;
    Base& rBase = derived;

    std::cout << "derived calls " << derived.getName();

    //getName calls Base fucntion but it is virtual so it looks for another version in
    // derived object
    std::cout << "\nrBase calls " << rBase.getName() << "\n";
}