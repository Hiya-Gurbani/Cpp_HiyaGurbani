#include <iostream>

class A {
private:
    int x = 42;
public:
    friend void show(A& a, int x);
};

class B {
private:
    int x = 99;
public:
//Declaring friend isn't enough we need to add obj too
    friend void show(A& a, int x); 
};

void show(A& a, int x) { 
    std::cout << "Value of A's x: " << a.x << "\nValue of local x: " << x << "\n";
    //Can't access B's private member
    // std::cout << "Value of B's x: " << b.x << "\nValue of local x: " << x << "\n";
}

int main() {
    A a;
    B b;
    show(a, 10);
}
