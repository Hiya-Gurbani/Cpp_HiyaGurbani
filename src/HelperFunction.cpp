#include "AllHeaders.h"

void printMenu() {
    std::cout << "\nOperations: \n";
    std::cout << "1. Matrix Addition\n2. Matrix Multiplication\n3. Exit\n";
}

void getMatrixDimensions(int& matrixRows, int& matrixColumns) {
    std::cout << "Enter the number of rows of matrix: ";
    inputValue(matrixRows);

    std::cout << "Enter the number of columns of matrix: ";
    inputValue(matrixColumns);
}

int** getMatricesDimensions(int numberOfMatrix) {
    int** matricesDimensions = allocateMatrix(numberOfMatrix, 2);

    for (int index = 0; index < numberOfMatrix; index++) {
        std::cout << "Matrix " << index + 1 << ":\n";
        getMatrixDimensions(matricesDimensions[index][0], matricesDimensions[index][1]);
    }

    return matricesDimensions;
}

bool areDimensionsValid(int** matricesDimensions, int numberOfMatrix) {
    for (int index = 1; index < numberOfMatrix; index++)
    {
        if (matricesDimensions[index - 1][1] != matricesDimensions[index][0])
        {
            std::cout << "Error: Matrices can't be multiplied! Dimensions are invalid.\n";
            return false;
        }
    }
    return true;
}

int** inputMatrixDimensions(int numberOfMatrices) {
    int** matricesDimensions;
    do {
        std::cout << "\nMatrix multiplication rule:\n"
                    "For every consecutive pair, columns of matrix i "
                    "must equal rows of matrix i+1.\n\n";

        matricesDimensions = getMatricesDimensions(numberOfMatrices);
    } while (!areDimensionsValid(matricesDimensions, numberOfMatrices));

    return matricesDimensions;
}

int** allocateMatrix(int matrixRows, int matrixColumns) {
    int** matrix = new int*[matrixRows]();
    for (int index = 0; index < matrixRows; index++)
    {
        matrix[index] = new int[matrixColumns]();
    }

    return matrix;
}

void inputMatrix(int** matrix, int matrixRows, int matrixColumns) {
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrixColumns; colIndex++)
        {
            std::cout << "Enter element of [" << rowIndex << "] [" << colIndex + "] : ";
            inputValue(*(*(matrix + rowIndex) + colIndex));
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMatrix(int** matrix, int matrixRows, int matrixColumns) {
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrixColumns; colIndex++)
        {
            std::cout << *(*(matrix + rowIndex) + colIndex) << " ";
        }
        std::cout << "\n";
    }
}

void deleteMatrix(int** matrix, int matrixRows) {
    for (int index = 0; index < matrixRows; index++)
    {
        delete[] matrix[index];
    }
    delete[] matrix;
}