#include "Logger.h"
#include <iostream>
#include <string>

const std::string Logger::MSG_OPERATIONS_MENU = 
                "\n===============Operations===============\n"
                "1. Matrix Addition\n"
                "2. Matrix Multiplication\n"
                "3. Exit\n"
                "========================================\n";
const std::string Logger::MSG_INPUT_CHOICE = "\nEnter your choice: ";
const std::string Logger::MSG_PROGRAM_EXIT = "Exiting Program...\n";

const std::string Logger::MSG_INVALID_NUMBER = "Invalid Input. Please enter a number: ";
const std::string Logger::MSG_INVALID_INTEGER = "Invalid Input. Please enter an integer: ";
const std::string Logger::MSG_OUT_OF_RANGE = "Invalid Value. Please enter an integer in range: ";
void Logger::inputMatrixElement(int rowIndex, int colIndex) {
    std::cout << "Enter element [" << rowIndex << "][" << colIndex << "] : ";
}
const std::string Logger::MSG_MATRIX_DIMENSIONS = "\nDimensions of Matrix ";
const std::string Logger::MSG_INPUT_ROWS = "\nEnter number of rows: ";
const std::string Logger::MSG_INPUT_COLUMNS = "Enter number of columns: ";
const std::string Logger::MSG_ROWS_NOTE = "\nNote: Rows must be ";
const std::string Logger::MSG_DIMENSION_MISMATCH = "Error: Matrix dimensions don't match. Try again.\n";

const std::string Logger::MSG_INPUT_MATRICES_NUMBER = "Enter number of matrices: ";
const std::string Logger::MSG_INPUT_MATRIX = "\nEnter Matrix ";
const std::string Logger::MSG_PERFORMING_ADDITION = "\nPerforming Matrix Addition: \n";
const std::string Logger::MSG_PERFORMING_MULTIPLY = "\nPerforming Matrix Multiplication: \n";
const std::string Logger::MSG_RESULTANT_MATRIX = "\nResultant Matrix:\n";


