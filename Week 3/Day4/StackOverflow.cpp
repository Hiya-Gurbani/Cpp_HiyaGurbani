#include <iostream>

void infiniteRecursion() {
    //Causes segmentation fault
    infiniteRecursion();
}

int main() {
    std::cout << "Starting infinite recursion leading to stack overflow..." << std::endl;
    infiniteRecursion();
    return 0;
}
