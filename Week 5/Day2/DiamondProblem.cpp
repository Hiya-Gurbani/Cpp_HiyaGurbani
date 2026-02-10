#include <iostream>

class Base {
public:
    void print() {
        std::cout << "Base!\n";
    }
};

class Parent1 : private Base {

};

class Parent2 : public Base {

};

class Derived : public Parent1, public Parent2 {

};

int main() {
    Derived d;
    d.print();
}