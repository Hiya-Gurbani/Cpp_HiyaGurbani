#include <iostream>

int main() {
    int size = 0;
    int* array = new int[size];  

    array[0] = 10;  
    std::cout << array[0] << "\n"; //Gives 10

    // if (size > 0) 
    // {
    //     array[0] = 10;  
    // }

    delete[] array;  
}
