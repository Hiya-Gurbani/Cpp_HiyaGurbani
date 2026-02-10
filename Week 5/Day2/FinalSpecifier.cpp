#include <iostream>

class Base {
    virtual void greet() {
        std::cout << "Base greet\n";
    }
};

class Parent {
public:
    virtual void greet() final {  
        std::cout << "Parent greet\n";
    }

    virtual void sayHi() {        
        std::cout << "Parent sayHi\n";
    }
};

class Child : public Parent {
public:
    // // This will cause an error: Overriding Final Function
    // void greet() override { 
    //     std::cout << "Child greet\n"; 
    // }
    
    void sayHi() override {
        std::cout << "Child sayHi\n";
    }
};

int main() {
    Parent* p = new Child();
    p->greet();   
    p->sayHi();   

    delete p;
    return 0;
}
