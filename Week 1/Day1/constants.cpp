#include <iostream>

int main() {
    const int pi = 3.14;

    //Wrong : need to initialised while declaration
    //const int value;
    //value = 5;

    //Could be initialised by another variable
    int value = 4;
    value = 5;
    const int constValue = value;

    value = 7; //Right
    constValue = 8; //Wrong
}