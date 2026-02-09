#include <iostream>
#include <string>

class Base {
public:
    virtual std::string getName() {
        return "Base";
    }
};

class Derived : public Base {
public:
    std::string getName() {
        return "Derived";
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