#include <iostream>

int main() {
    int* value1 = new int (5);
    int* value2 = new int; //Default Initialised --> Garbage
    int* value3 = new int (); //Value Initialised --> 0

    std::cout << value1 << " " << value2 << " " << value3 << "\n";
    std::cout << *value1 << " " << *value2 << " " << *value3 << "\n";

    delete(value1);
    delete(value2);
    delete(value3);

    value1 = value2 = value3 = nullptr; //Avoid Dangling Pointers
    // std::cout << *value1 << " " << *value2 << " " << *value3 << "\n"; //UB

    int value = 10;
    int* value4 = &value; 
    // delete(value4); //Error: called an unallocated object
}