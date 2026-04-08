#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <vector>
#include <utility>

namespace Constants {
    inline constexpr int COLUMN_WIDTH = 4;
    inline constexpr char OPEN_BRACKET  = '[';
    inline constexpr char CLOSE_BRACKET = ']';
    inline constexpr char COLON = ':';
    inline constexpr char WHITESPACE = ' ';
    inline constexpr char TAB = '\t';
    inline constexpr char NEW_LINE = '\n';
    inline constexpr char CHOICE_YES = 'y';
    inline constexpr char CHOICE_NO = 'n';

    inline const std::string MSG_NEW_LINE = "\n";
    inline const std::string MSG_INVALID_INTEGER = "Invalid Input. Please enter an integer: ";
    inline const std::string MSG_OUT_OF_RANGE = "Invalid Value. Please enter an integer greater than 0: ";
    inline const std::string MSG_INVALID_NUMBER = "Invalid Input. Please enter a number: ";
    inline const std::string MSG_INVALID_CHOICE = "\nInvalid input. Please enter y or n: ";
    
    inline const std::string MSG_INPUT_ROWS = "Enter the number of rows: ";  
    inline const std::string MSG_INPUT_COLS = "Enter the number of columns: ";  
    inline const std::string MSG_MATRIX1_DIMENSION = "\nMatrix 1 Dimensions: \n"; 
    inline const std::string MSG_NOTE = "\nNOTE: ";
    inline const std::string MSG_MATRIX2_DIMENSION = "Matrix 2 Dimensions: \n";
    inline const std::string MSG_INPUT_MATRIX1_VALUES = "\nEnter values of Matrix 1: \n";
    inline const std::string MSG_INPUT_MATRIX2_VALUES = "\nEnter values of Matrix 2: \n";
    inline const std::string MSG_MATRIX_MULTIPLICATION = "MATRIX MULTIPLICATION\n";
    inline const std::string MSG_MATRIX = "Matrix";
    inline const std::string MSG_INVALID_DIMENSIONS = "\nInvalid dimensions: Cannot multiply matrices.\n";
    inline const std::string MSG_MULTIPLICATION_NOTE = "Number of columns in the first matrix must equal the number of rows in the second matrix.\n";
    inline const std::string MSG_ENTER_AGAIN = "Please enter valid dimensions!\n\n";
    inline const std::string MSG_RESULTANT_MATRIX = "\nResultant Matrix: \n";
    inline const std::string MSG_CONTINUE = "\nDo you want to multiply another set of matrices (y/n): ";
    inline const std::string MSG_EXITING_PROGRAM = "\nThank you for using the program!\n";
}

#endif
