#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:

    inline static const std::string MSG_OPERATIONS_MENU = 
                    "\n===============Operations===============\n"
                    "1. Matrix Addition\n"
                    "2. Matrix Multiplication\n"
                    "3. Exit\n"
                    "========================================\n";
    inline static const std::string MSG_INPUT_CHOICE = "\nEnter your choice: ";
    inline static const std::string MSG_PROGRAM_EXIT = "Exiting Program...\n";

    inline static const std::string MSG_INVALID_NUMBER = "Invalid Input. Please enter a number: ";
    inline static const std::string MSG_INVALID_INTEGER = "Invalid Input. Please enter an integer: ";
    inline static const std::string MSG_OUT_OF_RANGE = "Invalid Value. Please enter an integer in range: ";
    inline static const std::string MSG_INPUT_MATRIX_ELEMENT = "Enter element ";

    inline static const std::string MSG_MATRIX_DIMENSIONS = "\nDimensions of Matrix ";
    inline static const std::string MSG_INPUT_ROWS = "\nEnter number of rows: ";
    inline static const std::string MSG_INPUT_COLUMNS = "Enter number of columns: ";
    inline static const std::string MSG_ROWS_NOTE = "\nNote: Rows must be ";
    inline static const std::string MSG_DIMENSION_MISMATCH = "Error: Matrix dimensions don't match. Try again.\n";

    inline static const std::string MSG_INPUT_MATRICES_NUMBER = "Enter number of matrices: ";
    inline static const std::string MSG_INPUT_MATRIX = "\nEnter Matrix ";
    inline static const std::string MSG_PERFORMING_ADDITION = "\nPerforming Matrix Addition: \n";
    inline static const std::string MSG_PERFORMING_MULTIPLY = "\nPerforming Matrix Multiplication: \n";
    inline static const std::string MSG_RESULTANT_MATRIX = "\nResultant Matrix:\n";

};

#endif
