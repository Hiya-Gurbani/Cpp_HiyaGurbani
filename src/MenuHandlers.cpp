#include "MenuHandlers.h"
#include "Constants.h"
#include "DimensionHelpers.h"
#include "Input.h"
#include "MatrixOperations.h"
#include "MatrixStructs.h"
#include <iostream>

void printMenu() {
    std::cout << "\n===============Operations===============\n"
              << "1. Matrix Addition\n"
              << "2. Matrix Multiplication\n"
              << "3. Exit\n"
              << "========================================\n";
}

bool handleMatrixAddition() {
    std::cout << "Enter number of matrices to add: ";
    int numberOfMatrix = inputValue(MIN_MATRICES, MAX_MATRICES);

    MatrixDimension dimension = getDimensions();

    Matrix result = addMultipleMatrices(numberOfMatrix, dimension);
    if (result.data)
    {
        std::cout << "\nResultant Matrix: \n";
        displayMatrix(result);
        deleteMatrix(result);
    }
    else
    {
        return false;
    }

    return true;
}

bool handleMatrixMultiplication() {
    std::cout << "Enter number of matrices to multiply: ";
    int numberOfMatrix = inputValue(MIN_MATRICES, MAX_MATRICES);
    bool isSuccess = false;

    MatrixDimension* dimensions = getValidMultipleDimensions(numberOfMatrix);
    if (dimensions)
    {
        Matrix result = multiplyMultipleMatrices(dimensions, numberOfMatrix);
        if (result.data)
        {
            std::cout << "\nResultant Matrix: \n";
            displayMatrix(result);
            deleteMatrix(result);
            isSuccess = true;
        }

        delete[] dimensions;
    }

    return isSuccess;
}

bool handleChoice(int choice) {
    bool continueProgram = true;

    switch (choice)
    {
        case 1:
        std::cout << "\nMatrix Addition Chosen!\n";
        continueProgram = handleMatrixAddition();
        break;

        case 2:
        std::cout << "\nMatrix Multiplication Chosen!\n";
        continueProgram = handleMatrixMultiplication();
        break;

        case 3:
        continueProgram = false;
        break;

        default:
        std::cout << "Invalid Choice! Please choose an option from the menu.\n";
    }
    
    return continueProgram;
}