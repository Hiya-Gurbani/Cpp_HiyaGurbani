#include <iostream>

class Base {
public:
    virtual void foo() = 0; 

    //Error: pure-specifier on function definition
    virtual void foo1() = 0 
    {
        std::cout << "Some VS code compilers allows this but standard doesn't\n";
    } 

    virtual ~Base() {}
};

void Base::foo() {
    std::cout << "Base::foo() default implementation\n";
}

class Derived : public Base {
public:
    void foo() override {
        std::cout << "Derived::foo() start\n";
        Base::foo();  // all base default
        std::cout << "Derived::foo() end\n";
    }
     
    void foo1() override {
        std::cout << "Derived::foo() start\n";
        Base::foo1();  // all base default
        std::cout << "Derived::foo() end\n";
    }
};

int main() {
    Derived d;
    d.foo();
}
