#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

class Logger {
public:
    static const std::string MSG_OPERATIONS_MENU;
    static const std::string MSG_INPUT_CHOICE;
    static const std::string MSG_INPUT_ELEMENT;

    // Input Handler Messages
    static const std::string MSG_INVALID_NUMBER;
    static const std::string MSG_INVALID_INTEGER;
    static const std::string MSG_OUT_OF_RANGE;

    // Menu Handler Messages
    static const std::string MSG_PERFORMING_ADDITION;
    static const std::string MSG_PERFORMING_MULTIPLY;

    static const std::string MSG_PROGRAM_EXIT;

    static const std::string MSG_INPUT_MATRICES_NUMBER;
};

#endif
