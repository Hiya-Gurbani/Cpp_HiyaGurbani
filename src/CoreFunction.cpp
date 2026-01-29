#include "AllHeaders.h"

void addMatrices(int** matrix1, int** matrix2, int matrixRows, int matrixColumns) {
    for (int rowIndex = 0; rowIndex < matrixRows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrixColumns; colIndex++)
        {
            *(*(matrix1 + rowIndex) + colIndex) = 
            *(*(matrix1 + rowIndex) + colIndex) + *(*(matrix2 + rowIndex) + colIndex);
        }
    }
}

int** addNMatrices(int numberOfMatrix, int matrixRows, int matrixColumns) {
    int** result = allocateMatrix(matrixRows, matrixColumns);
    int** nextMatrix = allocateMatrix(matrixRows, matrixColumns);

    std::cout << "Enter Matrix 1: \n";
    inputMatrix(result, matrixRows, matrixColumns);

    for (int index = 2; index <= numberOfMatrix; index++)
    {
        std::cout << "Enter the " << index << " array: ";
        inputMatrix(nextMatrix, matrixRows, matrixColumns);

        addMatrices(result, nextMatrix, matrixRows, matrixColumns);
    }

    deleteMatrix(nextMatrix, matrixRows);
    return result;
}

int** multiplyMatrices(int** matrix1, int** matrix2, int rows, int cols, int common) {
    int** result = allocateMatrix(rows, cols);
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

int** multiplyNMatrices(int** matrixDimensions, int numberOfMatrix) {
    int** result = allocateMatrix(matrixDimensions[0][0], matrixDimensions[0][1]);
    std::cout << "Enter Matrix 1: ";
    inputMatrix(result, matrixDimensions[0][0], matrixDimensions[0][1]);

    int currentResultRows = matrixDimensions[0][0];

    for (int index = 1; index < numberOfMatrix; index++)
    {
        int** nextMatrix = allocateMatrix(matrixDimensions[index][0], matrixDimensions[index][1]);
        std::cout << "Enter Matrix " << index + 1 << ": ";
        inputMatrix(nextMatrix, matrixDimensions[index][0], matrixDimensions[index][1]);

        int** tempResult = multiplyMatrices(result, nextMatrix, 
            currentResultRows, matrixDimensions[index][1], matrixDimensions[index][0]);

        deleteMatrix(result, currentResultRows);
        deleteMatrix(nextMatrix, matrixDimensions[index][0]);

        result = tempResult;
    }

    return result;
}