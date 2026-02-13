#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <iostream>

class Display {
public:
    static void printMessage(const std::string& message);
    
    static void printWithSuffix(const std::string& prefix, size_t value, const std::string& suffix);
    static void printWithNumber(const std::string& message, size_t number);
    static void printWithValue(const std::string& message, const std::string& value);
    static void printWithAmount(const std::string& message, double amount);

    static void printTransactionHeader();
    static void printTransactionRow(long id, const std::string& type, double amount, double postBalance);
    static void clearScreen();
};

#endif
