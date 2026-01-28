#include <iostream>
//Subtracting pointers of same type

int main() {
    int array[6] = {1, 2, 3, 4, 5, 6};

    int* pointer1 = &array[0];
    int* pointer2 = &array[4];


    std::cout << pointer2 - pointer1 << "\n";
}