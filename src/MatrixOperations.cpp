#include "AllHeaders.h"

Matrix createMatrix(MatrixDimension dimension) {
    Matrix matrix;
    matrix.dimension = dimension;
    matrix.data = new double*[dimension.rows]();

    for (int index = 0; index < dimension.rows; index++)
    {
        matrix.data[index] = new double[dimension.cols]();
    }

    return matrix;
}

void deleteMatrix(Matrix& matrix) {
    for (int index = 0; index < matrix.dimension.rows; index++)
    {
        delete[] matrix.data[index];
    }
    delete[] matrix.data;
    matrix.data = nullptr;
}

void inputMatrix(Matrix& matrix) {
    for (int rowIndex = 0; rowIndex < matrix.dimension.rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrix.dimension.cols; colIndex++)
        {
            std::cout << "Enter element [" << rowIndex << "][" << colIndex << "]: ";
            inputValue(*(*(matrix.data + rowIndex) + colIndex));
        }
    }
}

void displayMatrix(const Matrix& matrix) {
    for (int rowIndex = 0; rowIndex < matrix.dimension.rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrix.dimension.cols; colIndex++)
        {
            std::cout << *(*(matrix.data + rowIndex) + colIndex) << " ";
        }
        std::cout << "\n";
    }
}

void addMatricesInPlace(Matrix& result, const Matrix& matrix) {
    for (int rowIndex = 0; rowIndex < result.dimension.rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < result.dimension.cols; colIndex++)
        {
            *(*(result.data + rowIndex) + colIndex) += 
                                        *(*(matrix.data + rowIndex) + colIndex);
        }
    }
}

Matrix addMultipleMatrices(int numberOfMatrix, MatrixDimension dimension) {
    Matrix result = createMatrix(dimension);
    Matrix nextMatrix = createMatrix(dimension);

    std::cout << "\nEnter Matrix 1: \n";
    inputMatrix(result);

    for (int index = 2; index <= numberOfMatrix; index++)
    {
        std::cout << "\nEnter Matrix " << index << ": \n";
        inputMatrix(nextMatrix);

        addMatricesInPlace(result, nextMatrix);
    }

    deleteMatrix(nextMatrix);
    return result;
}

Matrix multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2) {
    MatrixDimension resultDimension = {matrix1.dimension.rows, matrix2.dimension.cols};
    Matrix result = createMatrix(resultDimension);

    for (int rowIndex = 0; rowIndex < matrix1.dimension.rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrix2.dimension.cols; colIndex++)
        {
            for (int k = 0; k < matrix2.dimension.rows; k++)
            {
                result.data[rowIndex][colIndex] += 
                            matrix1.data[rowIndex][k] * matrix2.data[k][colIndex];
            }
        }
    }
    return result;
}

Matrix multiplyMultipleMatrices(MatrixDimension* dimensions, int numberOfMatrix) {
    Matrix result = createMatrix(dimensions[0]);
    std::cout << "\nEnter Matrix 1: \n";
    inputMatrix(result);

    for (int index = 1; index < numberOfMatrix; index++)
    {
        Matrix nextMatrix = createMatrix(dimensions[index]);
        std::cout << "\nEnter Matrix " << index + 1 << ": \n";
        inputMatrix(nextMatrix);

        Matrix tempResult = multiplyMatrices(result, nextMatrix);

        deleteMatrix(result);
        deleteMatrix(nextMatrix);

        result = tempResult;
    }

    return result;
}