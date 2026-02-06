#include "InputHandler.h"
#include "Validator.h"
#include "Logger.h"
#include "Matrix.h"
#include <iostream>

double InputHandler::inputValue() {
    double value;

    while (true) 
    {
        std::cin >> value;
        if (Validator::isInputStreamValid())
        {
            break;
        }
        else
        {
            std::cout << Logger::MSG_INVALID_NUMBER;
        }
    }
    
    return value;
}

int InputHandler::inputValue(InputType input) {
    int value;
    while (true) 
    {
        std::cin >> value;
        if (!Validator::isInputStreamValid())
        {
            std::cout << Logger::MSG_INVALID_INTEGER;
        }
        else if (!Validator::isValidRange(input, value))
        {
            std::cout << Logger::MSG_OUT_OF_RANGE;
        } 
        else
        {
            break;
        }
    }
    return value;
}

Matrix& InputHandler::inputMatrix(Matrix& matrix) {
    for (int rowIndex = 0; rowIndex < matrix.getRows(); rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrix.getCols(); colIndex++)
        {
            std::cout << Logger::MSG_INPUT_ELEMENT << "[" << rowIndex << "][" << colIndex << "] : ";
            matrix.setMatrixElement(inputValue(), rowIndex, colIndex);
        }
    }
    return matrix;
}

void InputHandler::inputDimensionsForMultiplication(int numberofMatrices,
                int*& rows, int*& cols) {

    rows = new int[numberofMatrices];
    cols = new int[numberofMatrices];

    std::cout << "\nMatrix 1 dimensions: ";
    std::cout << "Enter number of rows: ";
    rows[0] = inputValue(ROWS);
    std::cout << "Enter number of columns: ";
    cols[0] = inputValue(COLUMNS);

    for (int index = 1; index < numberofMatrices; index++)
    {
        std::cout << "\nMatrix " << (index + 1) << " dimensions:\n";
        std::cout << "Note: Rows must be " << cols[index - 1] << "\n";
        
        while (true) {
            std::cout << "Enter number of rows: ";
            rows[index] = inputValue(ROWS);
            
            if (cols[index - 1] == rows[index]) 
            {
                break;
            }
            std::cout << "Error: Matrix " << (index + 1) 
                     << " must have " << cols[index - 1] 
                     << " rows. Try again.\n";
        }
        
        std::cout << "Enter number of columns: ";
        cols[index] = inputValue(COLUMNS);
    }
}