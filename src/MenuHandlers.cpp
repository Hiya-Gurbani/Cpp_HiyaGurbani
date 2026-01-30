#include "AllHeaders.h"

void printMenu() {
    std::cout << "\n===============Operations===============\n"
              << "1. Matrix Addition\n"
              << "2. Matrix Multiplication\n"
              << "3. Exit\n"
              << "========================================\n";
}

void handleMatrixAddition() {
    int numberOfMatrix;
    std::cout << "Enter number of matrices to add: ";
    inputValue(numberOfMatrix);

    MatrixDimension dimension = getDimensions();

    Matrix result = addMultipleMatrices(numberOfMatrix, dimension);

    std::cout << "\nResultant Matrix: \n";
    displayMatrix(result);

    deleteMatrix(result);
}

void handleMatrixMultiplication() {
    int numberOfMatrix;
    std::cout << "Enter number of matrices to multiply: ";
    inputValue(numberOfMatrix);

    MatrixDimension* dimensions = inputValidatedDimensions(numberOfMatrix);

    Matrix result = multiplyMultipleMatrices(dimensions, numberOfMatrix);

    std::cout << "\nResultant Matrix: \n";
    displayMatrix(result);
    
    deleteMatrix(result);
    delete[] dimensions;
}

bool handleChoice(int choice) {
    switch (choice)
    {
        case 1:
        std::cout << "\nMatrix Addition Chosen!\n";
        handleMatrixAddition();
        break;

        case 2:
        std::cout << "\nMatrix Multiplication Chosen!\n";
        handleMatrixMultiplication();
        break;

        case 3:
        return false;

        default:
        std::cout << "Invalid Choice! Please choose an option from the menu.\n";
    }
    
    return true;
}