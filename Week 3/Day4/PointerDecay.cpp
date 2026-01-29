#include <iostream>

void printArray(int array[]) {
    //Warning (Compiler Error): that sizeof(array) returns sizeof int* not array
    int size = sizeof(array) / sizeof(int);

    std::cout << "\nInside Function\n";
    for (int index = 0; index < size; index++)
    {
        std::cout << array[index] << " ";
    }
}

int main() {
    int array[] = {10, 20, 30, 40, 50};

    printArray(array);

    int size = sizeof(array) / sizeof(int);

    std::cout << "\nInside Main\n";
    for (int index = 0; index < size; index++)
    {
        std::cout << array[index] << " ";
    }
}