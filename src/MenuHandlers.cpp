#include "AllHeaders.h"

void printMenu() {
    std::cout << "\nOperations: \n";
    std::cout << "1. Matrix Addition\n2. Matrix Multiplication\n3. Exit\n";
}

void handleMatrixAddition() {
    int numberOfMatrix;
    std::cout << "Enter number of matrix you want to perform addition at: ";
    inputValue(numberOfMatrix);

    int matrixRows, matrixColumns;
    getDimensions(matrixRows, matrixColumns);

    double** result = addMultipleMatrices(numberOfMatrix, matrixRows, matrixColumns);

    std::cout << "Result: \n";
    displayMatrix(result, matrixRows, matrixColumns);

    deleteMatrix(result, matrixRows);
}

void handleMatrixMultiplication() {
    int numberOfMatrix;
    std::cout << "Enter number of matrix you want to perform multiplication at: ";
    inputValue(numberOfMatrix);

    MatrixDimension* matricesDimensions = inputValidatedDimensions(numberOfMatrix);

    double** result = multiplyMultipleMatrices(matricesDimensions, numberOfMatrix);

    std::cout << "Result: \n";
    displayMatrix(result, matricesDimensions[0].rows, matricesDimensions[numberOfMatrix -1].cols);
    
    deleteMatrix(result, matricesDimensions[0].rows);
    delete[] matricesDimensions;
}

bool handleChoice(int choice) {
    switch (choice)
    {
        case 1:
        std::cout << "\nMatrix Addition Chosen!\n";
        handleMatrixAddition();
        break;

        case 2:
        std::cout << "Matrix Multiplication Chosen!\n";
        handleMatrixMultiplication();
        break;

        case 3:
        return false;

        default:
        std::cout << "Invalid Choice! Choice one of options form menu.\n";
    }
    
    return true;
}