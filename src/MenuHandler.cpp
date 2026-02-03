#include "MenuHandler.h"
#include "Constants.h"
#include "DimensionHelper.h"
#include "Input.h"
#include "MatrixOperation.h"
#include "MatrixStruct.h"
#include "MatrixUtil.h"
#include <iostream>

void printMenu() {
    std::cout << "\n===============Operations===============\n"
              << "1. Matrix Addition\n"
              << "2. Matrix Multiplication\n"
              << "3. Exit\n"
              << "========================================\n";
}

bool handleMatrixAddition() {
    bool isSuccessful = false;

    std::cout << "Enter number of matrices to add (between " 
              << MIN_MATRICES << " and " << MAX_MATRICES << "): ";
    int numberOfMatrices = inputValue(MIN_MATRICES, MAX_MATRICES);

    MatrixDimension dimension = inputDimension();

    Matrix result = addMultipleMatrices(numberOfMatrices, dimension);
    if (result.data)
    {
        std::cout << "\nResultant Matrix: \n";
        displayMatrix(result);
        deleteMatrix(result);
        isSuccessful = true;
    }

    return isSuccessful;
}

bool handleMatrixMultiplication() {
    std::cout << "Enter number of matrices to multiply (between " 
              << MIN_MATRICES << " and " << MAX_MATRICES << "): ";
    int numberOfMatrices = inputValue(MIN_MATRICES, MAX_MATRICES);
    bool isSuccessful = false;

    MatrixDimension* dimensions = inputValidDimensions(numberOfMatrices);
    if (dimensions)
    {
        Matrix result = multiplyMultipleMatrices(dimensions, numberOfMatrices);
        if (result.data)
        {
            std::cout << "\nResultant Matrix: \n";
            displayMatrix(result);
            deleteMatrix(result);
            isSuccessful = true;
        }

        delete[] dimensions;
    }

    return isSuccessful;
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