#include <iostream>
#include <array>
#include <algorithm>

#define SIZE 5

void readArray(std::array<int, SIZE>& array) {
    for (int& element : array)
    {
        std::cin >> element;
    }
}

void printArray(const std::array<int, SIZE>& array) {
    for (int element : array)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

void reverseArray(std::array<int, SIZE>& array) {
    for (int index = 0; index < SIZE/2; index++)
    {
        std::swap(array[index], array[SIZE - index - 1]);
    }
}

int main() {
    std::array<int, SIZE> input;
    readArray(input);

    std::cout << "\nOriginal Input: \n";
    printArray(input);

    reverseArray(input);

    std::cout << "\nReversed Array: \n";
    printArray(input);
}