#include <iostream>
using namespace std;

class Base {
public:
    virtual void display(){
        cout << "Base display " << endl;
    }

    virtual void display(int x) {
        cout << "Base display with int: " << x << endl;
    }

    virtual void print() const override {
        cout << "Derived print (const)" << endl;
    }
};

class Derived : public Base {
public:
    void display() const override {
        cout << "Derived display (const)" << endl;
    }

    void display(short x) override {
        cout << "Derived display with int: " << x << endl;
    }

    //Syntax Error too. const before override always
    void print() override const {
        cout << "Derived print (const)" << endl;
    }
};

int main() {
    Derived d;
    Base* b1 = &d;
    Base* b2 = new Derived();

    // Invalid Conversion from Base to Derived
    // Derived* d1 = new Base();

    //Both give compiler error
    b1->display();       
    b2->display(42);     

    delete b1;
    delete b2;
    return 0;
}
