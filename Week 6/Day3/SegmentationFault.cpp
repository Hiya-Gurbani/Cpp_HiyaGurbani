#include <iostream>

void segmentationFaultExample() {
    int* ptr = nullptr;
    std::cout << "Attempting to write to null pointer...\n";
    *ptr = 42;  //Segmentation fault
}

void doubleDelete() {
    int* ptr = new int(5);
    delete ptr;
    delete ptr;
}

int main() {
    // segmentationFaultExample();
    doubleDelete();
    return 0;
}
