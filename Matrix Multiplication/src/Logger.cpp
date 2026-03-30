#include "../inc/Logger.h"
#include "../inc/Constants.h"
#include <iostream>
#include <iomanip>

void Logger::printMessage(const std::string& message) {
    std::cout << message;
}

void Logger::printMatrixElement(double element) {
    std::cout << std::setw(Constants::COLUMN_WIDTH) << element << Constants::WHITESPACE;
}
