#include <iostream>

//All fucntions are overloaded as the function signature is different

class Overload {
    public:

    Overload(int number1, int number2) {
        std::cout << "Overloaded Function 3\n";
    }

    Overload(char character, int number) {
        std::cout << "Overloaded Function 1\n";
    }

    Overload(int number, char character) {
        std::cout << "Overloaded Function 2\n";
    }
};

int main() {
    Overload over('a', 3); //No Ambiguity:  COmpiler searched for exact type first
}