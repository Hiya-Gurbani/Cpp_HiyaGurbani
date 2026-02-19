#ifndef UTILITY_H
#define UTILITY_H

#include "Constants.h"
#include <string>

class Utility {
public: 
    static std::string getFilePath();
    static void displayResults(Constants::ParsedData& data);
};

#endif
