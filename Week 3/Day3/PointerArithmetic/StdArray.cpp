#include <iostream>
#include <array>

int main() {
    std::array<int, 5> array = {10, 20, 30, 40, 50};

    int* ptr = array.data(); //or &arr[0];

    // std::cout << *(array + 2); Array
    std::cout << *(ptr + 2) << "\n";

    for (int* ptr = array.data(); ptr < array.data() + array.size(); ptr++)
    {
        std::cout << *ptr << " ";
    }
    std::cout << "\n";

    //array or array[0] doesn't decay to pointer
    for (int* ptr = &array[0]; ptr < &array[0] + array.size(); ptr++)
    {
        std::cout << *ptr << " ";
    }
    std::cout << "\n";

    ptr = &array[6];
    // std::cout << *ptr << "\n"; //Undefined behavior
}