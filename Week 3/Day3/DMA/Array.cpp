#include <iostream>

int main() {
    int size = 10;
    int* array = new int[size]; //Need size & default initialised
    int* array1 = new int[size] ();  //Zero initialised can also use { }
    int* array2 = new int; //Only 1 variable
    int* array3 = new int[5] {9, 5, 7, 3, 1}; //Allowed since C++11


    delete[] array; //delete array; -> causes UB
    delete[] array1; 
    delete array2; //delete[] array2; -> causes UB
    delete[] array3;
}