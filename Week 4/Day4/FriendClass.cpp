#include <iostream>

//Friendship gives access not merge member like inheritance

class B;

class A {
    int value = 10;
public:
    friend class B; // B can access private members of A
};

class B {
    int value = 20;
public:
    void show(const A& a) {
        std::cout << a.value << "\n"; // Accesses A's private value
        std::cout << value << "\n";   // Accesses B's own member

        //But if we have local var then it hides.
        //We have to do this->value then

        int value;
        std::cout << value << "\n";   // Refers to local variable, hides all others
        std::cout << a.value << "\n"; // Refers to A's value
        std::cout << this->value << "\n"; // Refers to B's member

    }
};

int main() {
    A a;
    B b;
    b.show(a);
}
