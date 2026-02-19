#include <iostream>

class Object {
public:
    Object() {
        std::cout << "Object Constructed!\n";
    }

    void example() noexcept {
        std::cout << "Example of: ";
        //warning throw will always call terminate
        throw std::runtime_error("Exception");  
    }

    ~Object() {
        //Warning throw will always call terminate
        // in c++11 deault to noexcept
        // throw std::runtime_error("Exception");
    }
};

int main() {
    try
    {
        Object obj;
        obj.example();
    }
    catch(std::exception& error)
    {
        std::cout << "Exception Occured!\n";
    }
}