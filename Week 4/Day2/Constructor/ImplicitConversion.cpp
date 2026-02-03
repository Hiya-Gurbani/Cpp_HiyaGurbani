#include <iostream>

class Constructor {
    int value1;
    int value2;

    public:  
    Constructor(int num1, int num2) {
        value1 = num1;
        value2 = num2;
        std::cout << "Cpnstructor Called!";
    }
};

int main() {
    //Will match for the arguments that are implicitly convertible to int
    Constructor c1(12.1, 'a');

    //String can't be converted: invalid conversion from const char* to int
    // Constructor c2("ab", 12);

    Constructor c3(1.2f, true);

}