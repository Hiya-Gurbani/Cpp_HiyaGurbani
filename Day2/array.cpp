#include <iostream>

int main() {
    //Garbage Values
    int array[2];
    for (int element : array)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";

    //Variable length arrays are not officially supported in C++
    int size;
    std::cin >> size;
    int array1[size];
    for (int element : array1)
    {
        std::cout << element << " ";
    }

}