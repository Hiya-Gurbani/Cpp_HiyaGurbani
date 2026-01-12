#include <iostream>

int main() {
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5] = {1, 2, 3};
    int array3[] = {1, 2, 3, 4, 5};
    // int array4[2] = {1, 2, 3, 4, 5}; Error: Too Many Initializers
    int array[5] = {0}; //All initialized to 0

    std::cout << sizeof(array1) << " " << sizeof(array2) << " " << sizeof(array3) << " ";

    std::cout << array2[3] << " " << array2[4] << " ";
    std::cout << array3[6] << " ";

    std::cout << array1 << " ";
    std::cout << &array1[0] << " ";

    int size;
    std::cin >> size;
    int array6[size];
}