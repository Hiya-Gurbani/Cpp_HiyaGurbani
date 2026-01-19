//Header guard do not prevent header file to be included once
//But it causes error as same function in main.cpp & square.cpp

#include "square.h" 
#include <iostream>

int main()
{
    std::cout << "a square has " << getSquareSides() << " sides\n";
    std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << '\n';

    return 0;
}