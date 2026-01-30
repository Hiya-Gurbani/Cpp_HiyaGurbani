#include <iostream>

int main() {
    int size = 0;
    int* array = new int[10];  

    //Undefined behavior
    // free(array);  
    // delete array;
    delete[] array;
}