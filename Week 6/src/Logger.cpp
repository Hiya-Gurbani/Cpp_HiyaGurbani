#include "Logger.h"
#include "Constants.h"
#include <iostream>
#include <iomanip>

void Logger::printMessage(const std::string& message) {
    std::cout << message;
}

void Logger::printNewLine() {
    std::cout << "\n";
}

void Logger::printField(const std::string& key, const std::string& value) {
    std::cout << "  " << std::left << std::setw(15) << key << " : " << value << "\n";
}
