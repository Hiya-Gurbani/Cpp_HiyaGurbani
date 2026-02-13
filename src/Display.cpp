#include "Display.h"
#include "Logger.h"
#include <cstdlib>
#include <iomanip>

void Display::printMessage(const std::string& message) {
    std::cout << message;
}

void Display::printLine(const std::string& message) {
    std::cout << message << std::endl;
}

void Display::printNewLine() {
    std::cout << std::endl;
}

void Display::printInvalidLength(size_t expectedLength) {
    std::cout << Logger::MSG_INVALID_LENGTH << expectedLength << Logger::MSG_DIGITS_SUFFIX;
}

void Display::printInvalidNameLength(size_t minLength) {
    std::cout << Logger::MSG_INVALID_NAME_LENGTH << minLength << Logger::MSG_CHARACTERS_SUFFIX;
}

void Display::printInvalidPasswordLength(size_t minLength) {
    std::cout << Logger::MSG_INVALID_PASSWORD_LENGTH << minLength << Logger::MSG_CHARACTERS_SUFFIX;
}

void Display::printAttemptsRemaining(int attempts) {
    std::cout << Logger::MSG_LEFT_ATTEMPTS << attempts << "\n";
}

void Display::printWithValue(const std::string& message, const std::string& value) {
    std::cout << message << value << "\n";
}

void Display::printWithNumber(const std::string& message, size_t number) {
    std::cout << message << number << "\n\n";
}

void Display::printWithAmount(const std::string& message, double amount) {
    std::cout << message << std::fixed << std::setprecision(2) << amount << "\n";
}

void Display::printTransactionHeader() {
    std::cout << std::setw(5) << "ID" 
              << std::setw(12) << "Type" 
              << std::setw(10) << "Amount" 
              << std::setw(15) << "Post Balance" << "\n";
}

void Display::printTransactionRow(long id, const std::string& type, double amount, double postBalance) {
    std::cout << std::setw(5) << id
              << std::setw(12) << type
              << std::setw(10) << std::fixed << std::setprecision(2) << amount
              << std::setw(15) << std::fixed << std::setprecision(2) << postBalance << "\n";
}


void Display::clearScreen() {
    system("clear");
}