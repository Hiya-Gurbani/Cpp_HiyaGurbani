#include <iostream>
#include <string>

class Ball {
    int size;
    std::string color;

    public:
    Ball() {
        std::cout << "Default Constructor Called! \n";
    } 
};

int main() {
    Ball ball1{}; //Value Initialization
    Ball ball2; //Default Initialization
}