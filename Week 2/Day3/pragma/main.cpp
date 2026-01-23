//The file path of product.h is different so pragma can't handle it 
//As compiler consider it a seperate file and doesn't check contents

#include "product.h"
// #include "utils.h"
#include "headers/product.h"
#include <iostream>

int main() {
    int value1, value2;
    std::cout << "Enter two sapce seperated integers: ";
    std::cin >> value1 >> value2;

    std::cout << "Result: " << product(value1, value2) << "\n";
}