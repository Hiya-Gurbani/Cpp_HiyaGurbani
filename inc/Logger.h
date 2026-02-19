#ifndef LOGGER_H
#define LOGGER_H

#include "Constants.h"
#include <string>

class Logger {
public:
    static void printMessage(const std::string& message);
    static void printResults(Constants::ParsedData& data);
};

#endif
