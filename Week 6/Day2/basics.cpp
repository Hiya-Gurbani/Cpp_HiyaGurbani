#include <iostream>

int add(int a, int b) {
    int sum = a + b;
    return sum;
}

int multiply(int a, int b) {
    int product = a * b;
    return product;
}

int main() {
    int x = 10;
    int y = 5;

    int sum = add(x, y);
    int product = multiply(x, y);

    std::cout << "Sum: " << sum << "\n";
    std::cout << "Product: " << product << "\n";
    return 0;
}
