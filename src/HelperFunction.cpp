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

MatrixDimension* getMatricesDimensions(int numberOfMatrix) {
    MatrixDimension* matricesDimensions = new MatrixDimension[numberOfMatrix];

    for (int index = 0; index < numberOfMatrix; index++) {
        std::cout << "Matrix " << index + 1 << ":\n";
        getMatrixDimensions(matricesDimensions[index].rows, 
        matricesDimensions[index].cols);
    }

    return matricesDimensions;
}

bool areDimensionsValid(MatrixDimension* matricesDimensions, int numberOfMatrix) {
    for (int index = 1; index < numberOfMatrix; index++)
    {
        if (matricesDimensions[index - 1].cols != matricesDimensions[index].rows)
        {
            std::cout << "Error: Matrices can't be multiplied! Dimensions are invalid.\n";
            return false;
        }
    }
    return true;
}

MatrixDimension* inputMatrixDimensions(int numberOfMatrices) {
    MatrixDimension* matricesDimensions;
    do {
        std::cout << "\nMatrix multiplication rule:\n"
                    "For every consecutive pair, columns of matrix i "
                    "must equal rows of matrix i+1.\n\n";

        matricesDimensions = getMatricesDimensions(numberOfMatrices);
    } while (!areDimensionsValid(matricesDimensions, numberOfMatrices));

    return matricesDimensions;
}

double** allocateMatrix(int matrixRows, int matrixColumns) {
    double** matrix = new double*[matrixRows]();
    for (int index = 0; index < matrixRows; index++)
    {
        matrix[index] = new double[matrixColumns]();
    }

    return matrix;
}

void inputMatrix(double** matrix, int matrixRows, int matrixColumns) {
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrixColumns; colIndex++)
        {
            std::cout << "Enter element at [" << rowIndex << "][" << colIndex << "] : ";
            inputValue(*(*(matrix + rowIndex) + colIndex));
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMatrix(double** matrix, int matrixRows, int matrixColumns) {
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrixColumns; colIndex++)
        {
            std::cout << *(*(matrix + rowIndex) + colIndex) << " ";
        }
        std::cout << "\n";
    }
}

void deleteMatrix(double** matrix, int matrixRows) {
    for (int index = 0; index < matrixRows; index++)
    {
        delete[] matrix[index];
    }
    delete[] matrix;
}