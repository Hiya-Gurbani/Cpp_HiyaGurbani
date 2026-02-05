#include <iostream>

class Base {
public:
    void display() {
        std::cout << "Base Class\n";
    }
};

class Parent1 : public Base {
};

class Parent2 : public Base {
};

class Child : public Parent1, public Parent2 {
};

int main() {
    Child child;
    // child.display(); //Ambiguous request
    // child.Base::display(); //Base is ambiguous base of child
    child.Parent1::display(); //Works in this way
}

