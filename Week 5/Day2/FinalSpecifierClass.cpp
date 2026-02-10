#include <iostream>

class Base final {   
public:
    void show() {
        std::cout << "Base show\n";
    }
};

// This will cause a compile-time error: cannot derive from final
class Derived : public Base { };

int main() {

}


