#include <iostream>
using namespace std;
 
class Base {
public:
    virtual const char* msg() { return "Base"; }
};
 
class Derived : public Base {
public:
    const char* msg() override { return "Derived"; }
};
 
int main() {
    try {
        throw Derived();
    }
    catch (Base b) {    //Object Slicing
        cout << b.msg();
    }
}