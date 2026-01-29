#include <iostream>

int main() {
    void* ptr = new int(42);     

    //Error: void* int not pointer-to-object type
    // std::cout << *ptr;

    std::cout << *static_cast<int*>(ptr);  // cast void* to int* and dereference

    //Warning (Compiler Error): deleting void* is undefined
    // delete ptr;
    delete static_cast<int*>(ptr);    
    return 0;
}
