#include <iostream>

int main() {
    int* ptr;
    
    //Undefined Behavior --> Segmentation Fault
    std::cout << *ptr << "\n";
}