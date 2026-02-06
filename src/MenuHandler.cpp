#include "MenuHandler.h"
#include "InputHandler.h"
#include "Logger.h"
#include "Matrix.h"
#include <iostream>

void MenuHandler::printMenu() {
    std::cout << "\n===============Operations===============\n"
            << "1. Matrix Addition\n"
            << "2. Matrix Multiplication\n"
            << "3. Exit\n"
            << "========================================\n";
}

Matrix MenuHandler::performMatrixAddition() {
    std::cout << Logger::MSG_INPUT_MATRICES_NUMBER;
    int numberOfMatrices = InputHandler::inputValue(MATRICES_NUMBER);

    std::cout << "Enter number of rows: ";
    int rows = InputHandler::inputValue(ROWS);
    std::cout << "Enter number of columns: ";
    int cols = InputHandler::inputValue(COLUMNS);

    Matrix result(rows, cols);
    std::cout << "Enter Matrix 1: \n";
    InputHandler::inputMatrix(result);

    Matrix sourceMatrix(rows, cols);
    for (int index = 2; index <= numberOfMatrices; index++)
    {
        std::cout << "Enter Matrix " << index << ": \n";
        InputHandler::inputMatrix(sourceMatrix);
        result += sourceMatrix;
    }

    std::cout << "\nResultant Matrix:\n";
    result.displayMatrix();

    return result;
}

Matrix MenuHandler::performMatrixMultiplication() {
    std::cout << Logger::MSG_INPUT_MATRICES_NUMBER;
    int numberOfMatrices = InputHandler::inputValue(MATRICES_NUMBER);

    int* rowsArray = nullptr;
    int* colsArray = nullptr;
    InputHandler::inputDimensionsForMultiplication(numberOfMatrices, rowsArray, colsArray);

    Matrix result(rowsArray[0], colsArray[0]);
    std::cout << "Enter Matrix 1:";
    InputHandler::inputMatrix(result);

    for (int index = 1; index < numberOfMatrices; index++)
    {
        Matrix nextMatrix(rowsArray[index], colsArray[index]);
        std::cout << "\nEnter Matrix " << (index + 1) << ":\n";
        InputHandler::inputMatrix(nextMatrix);
        
        Matrix tempResult = result * nextMatrix;
        result = tempResult;
    }

    delete[] rowsArray;
    delete[] colsArray;

    std::cout << "\nResultant Matrix:\n";
    result.displayMatrix();
    
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
        break;
    }
    
    return continueProgram;
}