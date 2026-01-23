#include "Globals.h"
#include <iostream>

int globalCount = 0;

void incrementCount() {
    globalCount++;
    std::cout << "Global Count is: " << globalCount << "\n";
}