#include <iostream>

class Base {
public:
    virtual void mustImplement() = 0;   

    //We can access this either by derived or Base* with derived object
    void commonLogic() {                
        std::cout << "Shared logic\n";
    }

    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void mustImplement() override {
        std::cout << "Derived implementation\n";
    }
};

int main() {
    Derived d;
    d.commonLogic();        
    d.mustImplement();      

    Base* b = &d;
    b->commonLogic();       
    b->mustImplement();    
}
