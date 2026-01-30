#include "AllHeaders.h"

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

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void addMatricesInPlace(double** matrix1, double** matrix2, int matrixRows, int matrixColumns) {
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrixColumns; colIndex++)
        {
            *(*(matrix1 + rowIndex) + colIndex) = 
            *(*(matrix1 + rowIndex) + colIndex) + *(*(matrix2 + rowIndex) + colIndex);
        }
    }
}

double** addMultipleMatrices(int numberOfMatrix, int matrixRows, int matrixColumns) {
    double** result = allocateMatrix(matrixRows, matrixColumns);
    double** nextMatrix = allocateMatrix(matrixRows, matrixColumns);

    std::cout << "Enter Matrix 1: \n";
    inputMatrix(result, matrixRows, matrixColumns);

    for (int index = 2; index <= numberOfMatrix; index++)
    {
        std::cout << "Enter the " << index << " array: ";
        inputMatrix(nextMatrix, matrixRows, matrixColumns);

        addMatricesInPlace(result, nextMatrix, matrixRows, matrixColumns);
    }

    deleteMatrix(nextMatrix, matrixRows);
    return result;
}

double** multiplyMatrices(double** matrix1, double** matrix2, int rows, int cols, int common) {
    double** result = allocateMatrix(rows, cols);
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            for (int k = 0; k < common; k++)
            {
                result[rowIndex][colIndex] += 
                            matrix1[rowIndex][k] * matrix2[k][colIndex];
            }
        }
    }
    return result;
}

double** multiplyMultipleMatrices(MatrixDimension* matrixDimensions, int numberOfMatrix) {
    double** result = allocateMatrix(matrixDimensions[0].rows, matrixDimensions[0].cols);
    std::cout << "Enter Matrix 1: ";
    inputMatrix(result, matrixDimensions[0].rows, matrixDimensions[0].cols);

    int currentResultRows = matrixDimensions[0].rows;

    for (int index = 1; index < numberOfMatrix; index++)
    {
        double** nextMatrix = allocateMatrix(matrixDimensions[index].rows, matrixDimensions[index].cols);
        std::cout << "Enter Matrix " << index + 1 << ": ";
        inputMatrix(nextMatrix, matrixDimensions[index].rows, matrixDimensions[index].cols);

        double** tempResult = multiplyMatrices(result, nextMatrix, 
            currentResultRows, matrixDimensions[index].cols, matrixDimensions[index].rows);

        deleteMatrix(result, currentResultRows);
        deleteMatrix(nextMatrix, matrixDimensions[index].rows);

        result = tempResult;
    }

    return result;
}