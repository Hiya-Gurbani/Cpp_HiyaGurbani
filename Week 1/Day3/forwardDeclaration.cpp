#include <iostream>

int sum(int x, int y);

int main() {
    int x = 5;
    int y = 5;

    std::cout << sum(x, y); //If no definition, Error: undefined reference
}