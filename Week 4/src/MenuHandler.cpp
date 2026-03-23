#include "MenuHandler.h"
#include "Constants.h"
#include "InputHandler.h"
#include "Logger.h"
#include "Matrix.h"
#include "Validator.h"
#include <iostream>

Matrix MenuHandler::performMatrixAddition() {
    std::cout << Logger::MSG_INPUT_MATRICES_NUMBER;
    int numberOfMatrices = InputHandler::inputValue(MATRICES_NUMBER);

    std::cout << Logger::MSG_INPUT_ROWS;
    int rows = InputHandler::inputValue(ROWS);
    std::cout << Logger::MSG_INPUT_COLUMNS;
    int cols = InputHandler::inputValue(COLUMNS);

    Matrix result(rows, cols);
    int index = 1;
    std::cout << Logger::MSG_INPUT_MATRIX << index << Constants::NEWLINE_SPACE;
    InputHandler::inputMatrix(result);

    Matrix nextMatrix(rows, cols);
    for (index = 2; index <= numberOfMatrices; index++)
    {
        std::cout << Logger::MSG_INPUT_MATRIX << index << Constants::NEWLINE_SPACE;
        InputHandler::inputMatrix(nextMatrix);
        result += nextMatrix;
    }

    return result;
}

Matrix MenuHandler::performMatrixMultiplication() {
    std::cout << Logger::MSG_INPUT_MATRICES_NUMBER;
    int numberOfMatrices = InputHandler::inputValue(MATRICES_NUMBER);

    int* rowsArray = new int[numberOfMatrices];
    int* colsArray = new int[numberOfMatrices];
    InputHandler::inputDimensionsForMultiplication(numberOfMatrices, rowsArray, colsArray);

    Matrix result(rowsArray[0], colsArray[0]);
    int index = 1;
    std::cout << Logger::MSG_INPUT_MATRIX << index << Constants::NEWLINE_SPACE;
    InputHandler::inputMatrix(result);

    for (index = 1; index < numberOfMatrices; index++)
    {
        Matrix nextMatrix(rowsArray[index], colsArray[index]);
        std::cout << Logger::MSG_INPUT_MATRIX << index + 1 << Constants::NEWLINE_SPACE;
        InputHandler::inputMatrix(nextMatrix);
        
        result = result * nextMatrix;
    }

    delete[] rowsArray;
    delete[] colsArray;
    
    return result;
}

bool MenuHandler::handleChoice(int choice) {
    bool continueProgram = true;
    Matrix result;

    switch (choice)
    {
        case 1:
        std::cout << Logger::MSG_PERFORMING_ADDITION;
        result = performMatrixAddition();
        break;

        case 2:
        std::cout << Logger::MSG_PERFORMING_MULTIPLY;
        result = performMatrixMultiplication();
        break;

        case 3:
        continueProgram = false;
    }

    if (continueProgram)
    {
        std::cout << Logger::MSG_RESULTANT_MATRIX;
        result.displayMatrix();
    }
    
    return continueProgram;
}
