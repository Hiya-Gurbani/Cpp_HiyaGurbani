#include "Rescue.h"
#include <iostream>
#include <string>

void logInfo(const std::string &msg) {
    std::cout << msg << "\n";
}

void logError(const std::string &msg) {
    std::cerr << msg << "\n";
}

bool checkDisk() {
    return true;
}
