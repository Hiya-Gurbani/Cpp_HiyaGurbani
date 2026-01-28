#include <iostream>

int main() {
    int array[] = {10, 20, 30, 40, 50};
    int *ptr = array;

    std::cout << array[2] << "\n";
    std::cout << *(array + 2) << "\n";

    std::cout << ptr[2] << "\n";
    std::cout << *(ptr + 2) << "\n";

    std::cout << array[4] << "\n";
    std::cout << array[6] << "\n"; //Garbage Value

    //Loop
    for (int* ptr = array; ptr < array + 5; ptr++)
    {
        std::cout << *ptr << " ";
        std::cout << *ptr + 1 << " ";
    }
    std::cout << "\n";
}