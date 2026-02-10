#include <string>

class Base
{
public:
    std::string sayHi() { 
        return "Non-Virtual Function";
    } 

    virtual std::string getName() { 
        return "Virtual Function"; 
    } 

    virtual int getValue() const = 0; //Pure Virtual Function

    int doSomething() = 0; //Compile error: can not set non-virtual functions to 0
};

int main() {
    //Base is an abstract class it can't be instantiated
    //Compiler error: can't declare b to be of abstract type Base
    Base b;
}