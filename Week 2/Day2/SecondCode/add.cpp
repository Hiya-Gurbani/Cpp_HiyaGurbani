//Its good to include paired header to its src file
#include "add.h" 

//As if their is an issue with declaration we'll know at compile time
//Else we'll face undefined behavior
double add(int value1, int value2) {
    return value1 + value2;
}