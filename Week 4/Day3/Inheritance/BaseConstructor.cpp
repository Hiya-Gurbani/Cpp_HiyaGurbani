#include <iostream>

class Base {
protected:
    const int id;
public:
    Base(int currId)
    : id {currId} {
        std::cout << "Base Constructor Called\n";
    }
};

class Derived : public Base {
    int value;
public:
    Derived(int currId, int baseId)
    : value {currId}, Base {baseId} {
        std::cout << "Derived Constructor Called\n";
    }

    void print() {
        std::cout << "Base ID: " << id << "\nDerived ID: " << value << "\n";
    }
};

int main() {
    Derived d(12, 10);
    std::cout << sizeof(d) << "\n"; 

    d.print();
}