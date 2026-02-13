#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <iostream>

class Display {
public:
    static void printMessage(const std::string& message);
    static void printLine(const std::string& message);
    static void printNewLine();
    
    static void printInvalidLength(size_t expectedLength);
    static void printInvalidNameLength(size_t minLength);
    static void printInvalidPasswordLength(size_t minLength);
    
    static void printAttemptsRemaining(int attempts);

    static void printWithValue(const std::string& message, const std::string& value);
    static void printWithNumber(const std::string& message, size_t number);
    static void printWithAmount(const std::string& message, double amount);

    static void printTransactionHeader();
    static void printTransactionRow(long id, const std::string& type, double amount, double postBalance);
    static void clearScreen();
};

#endif