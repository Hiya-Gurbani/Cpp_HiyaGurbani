//Necessary include as header contains extern "C" -- Without it multiply gets mangled
#include "Plugin.h" 
#include <iostream>

int multiply(int value1, int value2) {
    return value1 * value2;
}