//Variable: Object with a name
//Object: Region of storage that can hold a value

#include <iostream>

int main() {
    int value; //Definition of x variable

    //Multiple Variables
    int value1;
    int value2;

    //OR   int value1, value2;


    int width, height; //Defining Variables
    width = 0; //Assignment to Variable
    //The assigned value is returned by assignment expression
    height = (width = 10); // height = weight = 10;
    std::cout << height << std::endl;  


    //If running code with -Werror, to avoid unused variable errors
    [[maybe_unused]] double pi {3.14}; 
}