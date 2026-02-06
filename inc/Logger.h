#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    static const std::string MSG_OPERATIONS_MENU;
    static const std::string MSG_INPUT_CHOICE;
    static const std::string MSG_PROGRAM_EXIT;

    static const std::string MSG_INVALID_NUMBER;
    static const std::string MSG_INVALID_INTEGER;
    static const std::string MSG_OUT_OF_RANGE;
    static void inputMatrixElement(int rowIndex, int colIndex); 
    static const std::string MSG_MATRIX_DIMENSIONS;
    static const std::string MSG_INPUT_ROWS;
    static const std::string MSG_INPUT_COLUMNS;
    static const std::string MSG_ROWS_NOTE;
    static const std::string MSG_DIMENSION_MISMATCH;

    static const std::string MSG_INPUT_MATRICES_NUMBER;
    static const std::string MSG_INPUT_MATRIX;
    static const std::string MSG_PERFORMING_ADDITION;
    static const std::string MSG_PERFORMING_MULTIPLY;
    static const std::string MSG_RESULTANT_MATRIX;
};

#endif
