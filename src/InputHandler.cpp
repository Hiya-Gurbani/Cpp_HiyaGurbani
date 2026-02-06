#include "InputHandler.h"
#include "Validator.h"
#include "Constants.h"
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
        else if (!Validator::isValueInValidRange(input, value))
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

void InputHandler::inputMatrix(Matrix& matrix) {
    for (int rowIndex = 0; rowIndex < matrix.getRows(); rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrix.getCols(); colIndex++)
        {
            Logger::inputMatrixElement(rowIndex, colIndex);
            matrix.setElementAt(inputValue(), rowIndex, colIndex);
        }
    }
}

void InputHandler::inputDimensionsForMultiplication(int numberOfMatrices,
                int*& rowsArray, int*& colsArray) {

    int index = 1;
    std::cout << Logger::MSG_MATRIX_DIMENSIONS << index;
    std::cout << Logger::MSG_INPUT_ROWS;
    rowsArray[0] = inputValue(ROWS);
    std::cout << Logger::MSG_INPUT_COLUMNS;
    colsArray[0] = inputValue(COLUMNS);

    for (index = 1; index < numberOfMatrices; index++)
    {
        std::cout << Logger::MSG_MATRIX_DIMENSIONS << index + 1;
        std::cout << Logger::MSG_ROWS_NOTE << colsArray[index - 1] << Constants::NEWLINE_SPACE;
        
        while (true) {
            std::cout << Logger::MSG_INPUT_ROWS;
            rowsArray[index] = inputValue(ROWS);
            
            if (colsArray[index - 1] == rowsArray[index]) 
            {
                break;
            }
            std::cout << Logger::MSG_DIMENSION_MISMATCH;
        }
        
        std::cout << Logger::MSG_INPUT_COLUMNS;
        colsArray[index] = inputValue(COLUMNS);
    }
}