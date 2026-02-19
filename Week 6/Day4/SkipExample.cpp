#include <iostream>

void helper1() {
    std::cout << "Inside helper1\n";
}

void helper2() {
    std::cout << "Inside helper2\n";
}

int computeSum(int a, int b) {
    std::cout << "Computing sum\n";
    return a + b;
}

int main() {
    std::cout << "Program started\n";

    helper1();
    int result = computeSum(5, 10);
    helper2();

    std::cout << "Result: " << result << std::endl;
    std::cout << "Program ended\n";
    return 0;
}
