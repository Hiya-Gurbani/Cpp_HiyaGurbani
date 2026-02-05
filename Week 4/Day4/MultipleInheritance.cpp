#include <iostream>

class Parent1 {
public:
    Parent1() {
        std::cout << "Parent 1\n";
    }
    ~Parent1() {
        std::cout << "~Parent 1\n";
    }
};

class Parent2 {
public:
    Parent2() {
        std::cout << "Parent 2\n";
    }
    ~Parent2() {
        std::cout << "~Parent 2\n";
    }
};

class Child1 : public Parent1, public Parent2 {
public:
    Child1() {
        std::cout << "Child 1\n";
    }
    ~Child1() {
        std::cout << "~Child 1\n";
    }
};

class Child2 : public Parent2, public Parent1 {
public:
    Child2() {
        std::cout << "Child 2\n";
    }
    ~Child2() {
        std::cout << "~Child 2\n";
    }
};

int main() {
    {
        Child1 child1;
    }

    std::cout << "\n\n";

    Child2 child2;
}

