#include "AllHeaders.h"

void handleMatrixAddition() {
    int numberOfMatrix;
    std::cout << "Enter number of matrix you want to perform addition at: ";
    inputValue(numberOfMatrix);

    int matrixRows, matrixColumns;
    getMatrixDimensions(matrixRows, matrixColumns);

    int** result = addNMatrices(numberOfMatrix, matrixRows, matrixColumns);

    std::cout << "Result: \n";
    displayMatrix(result, matrixRows, matrixColumns);

    deleteMatrix(result, matrixRows);
}

void handleMatrixMultiplication() {
    int numberOfMatrix;
    std::cout << "Enter number of matrix you want to perform multiplication at: ";
    std::cin >> numberOfMatrix;

    int** matricesDimensions = inputMatrixDimensions(numberOfMatrix);

    int** result = multiplyNMatrices(matricesDimensions, numberOfMatrix);

    std::cout << "Result: \n";
    displayMatrix(result, matricesDimensions[0][0], matricesDimensions[numberOfMatrix -1][1]);
    
    deleteMatrix(result, matricesDimensions[0][0]);
    deleteMatrix(matricesDimensions, numberOfMatrix);
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