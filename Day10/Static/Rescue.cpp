#include "rescue.h"
#include <iostream>

void logInfo(const std::string &msg) {
    std::cout << msg << std::endl;
}

void logError(const std::string &msg) {
    std::cerr << msg << std::endl;
}

bool checkDisk() {
    return true;
}
