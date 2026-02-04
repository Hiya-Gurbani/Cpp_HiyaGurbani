#include <iostream>

class Example {
    int x;  
    int y;  
public:
    //Order of member initializer list doesn't matter
    // Example(int val) : x(y), y(val) {} Same for both constructors 

    Example(int val) : y(val), x(y) {}  

    void print() {
        std::cout << x << " " << y;
    }
};

int main() {
    Example example(12);
    example.print(); //x = 0 and y = 12
    //because member vars are initilalsed in the order they are declared 
}