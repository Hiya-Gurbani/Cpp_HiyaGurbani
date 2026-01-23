#include "Globals.h"
#include <iostream>

extern void incrementCount();

int main() {
    std::cout << "Initial Count: " << globalCount << "\n";

    incrementCount();
    incrementCount();

    std::cout << "Final count in main: " << globalCount << "\n";
}