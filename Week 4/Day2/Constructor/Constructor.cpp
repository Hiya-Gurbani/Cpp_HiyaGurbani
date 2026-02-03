#include <iostream>

class Constructor {
    int value;

    public:  //If we remove it error: private within this context
    Constructor() {
        value = 10;
        std::cout << "Constructor Called!\n";
    }

    void print() {
        std::cout << value << "\n";
    }
};

int main() {
    Constructor c;
    c.print();
}