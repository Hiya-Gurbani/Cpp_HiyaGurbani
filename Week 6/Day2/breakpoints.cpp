#include <iostream>
#include <string>

void countUp(int limit) {
    for (int i = 0; i < limit; i++) {
        std::cout << "i = " << i << "\n";   
    }
}

int factorial(int n) {
    if (n <= 1) 
    {
        return 1;
    }
    return n * factorial(n - 1);   
}

void greet(const std::string& name) {
    std::string msg = "Hello, " + name + "!";
    std::cout << msg << "\n";
}

int main() {
    countUp(8);
    int f = factorial(5);
    greet("Alice"); greet("Bob"); greet("Carol");
    return 0;
}