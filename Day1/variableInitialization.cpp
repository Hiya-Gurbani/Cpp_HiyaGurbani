#include <iostream>

int globalVariable; //Default Initialised to 0

int main() {
    int length = 0; //Initializing variable to 0

    //Types of initialization
    int num1; //Default Initialization --> Garbage Value

    int num2 = 5; //Copy Initialization

    int num3 ( 10 ); //Direct Initialization

    int num4 { 15 }; //Direct List Initialization

    int num5 {}; //Value Initialization
}