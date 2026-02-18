#include <iostream>

void memoryLeakExample() {
    int* arr = new int[5];  
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }

    std::cout << "Array values: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Forgot to free memory -> memory leak
    // delete[] arr;
}

int main() {
    memoryLeakExample();
    return 0;
}
