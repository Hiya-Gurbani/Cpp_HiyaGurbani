#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H

#include "ILogger.h"
#include <iostream>

class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "[LOG]: " << message << std::endl;
    }
};

#endif
