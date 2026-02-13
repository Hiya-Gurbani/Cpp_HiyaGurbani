#include "Display.h"
#include "Logger.h"
#include "Constants.h"
#include <cstdlib>
#include <iomanip>

void Display::printMessage(const std::string& message) {
    std::cout << message;
}

void Display::printWithSuffix(const std::string& prefix, size_t value, const std::string& suffix) {
    std::cout << prefix << value << suffix;
}

void Display::printWithValue(const std::string& message, const std::string& value) {
    std::cout << message << value << Constants::NEW_LINE;
}

void Display::printWithNumber(const std::string& message, size_t number) {
    std::cout << message << number << Constants::NEW_LINE;
}

void Display::printWithAmount(const std::string& message, double amount) {
    std::cout << message << std::setprecision(2) << amount << Constants::NEW_LINE;
}

void Display::printTransactionHeader() {
    std::cout << std::setw(Constants::ID_WIDTH) << Logger::MSG_TRANSACTION_HEADER_ID
              << std::setw(Constants::TYPE_WIDTH) << Logger::MSG_TRANSACTION_HEADER_TYPE
              << std::setw(Constants::AMOUNT_WIDTH) << Logger::MSG_TRANSACTION_HEADER_AMOUNT
              << std::setw(Constants::POSTBALANCE_WIDTH) << Logger::MSG_TRANSACTION_HEADER_POSTBAL
              << Constants::NEW_LINE;
}


void Display::printTransactionRow(long id, const std::string& type, double amount, double postBalance) {
    std::cout << std::setw(Constants::ID_WIDTH) << id
              << std::setw(Constants::TYPE_WIDTH) << type
              << std::setw(Constants::AMOUNT_WIDTH) << std::setprecision(Constants::DECIMAL_PRECISION) << amount
              << std::setw(Constants::POSTBALANCE_WIDTH) << std::setprecision(Constants::DECIMAL_PRECISION) << postBalance << Constants::NEW_LINE;
}

void Display::clearScreen() {
    system(Logger::CLEAR_SCREEN.c_str());
}
