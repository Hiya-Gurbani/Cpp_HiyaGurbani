#include "MatrixOperations.h"
#include "Input.h"
#include "MatrixStructs.h"
#include <iostream>
#include <iomanip>

void deleteMatrix(Matrix& matrix) {
    if (!matrix.data)
    {
        return;
    }
    
    for (int rowIndex = 0; rowIndex < matrix.dimension.rows; rowIndex++)
    {
        delete[] *(matrix.data + rowIndex);
    }
    delete[] matrix.data;
    matrix.data = nullptr;
    matrix.dimension.rows = matrix.dimension.cols = 0;
}

Matrix createMatrix(MatrixDimension dimension) {
    Matrix matrix;
    matrix.dimension = dimension;

    matrix.data = new(std::nothrow) double*[dimension.rows]();
    if (matrix.data)
    {
        for (int rowIndex = 0; rowIndex < dimension.rows; rowIndex++)
        {
            *(matrix.data + rowIndex) = new (std::nothrow) double[dimension.cols]();
            if (!matrix.data[rowIndex])
            {
                deleteMatrix(matrix); 
                break;
            }
        }
    }
    if (!matrix.data)
    {
        std::cerr << "Error: Failed to allocate memory\n";
    }

    return matrix;
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
    const int columnWidth = 4;
    for (int rowIndex = 0; rowIndex < matrix.dimension.rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrix.dimension.cols; colIndex++)
        {
            std::cout << std::setw(columnWidth) << 
            *(*(matrix.data + rowIndex) + colIndex) << " ";
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
    if (result.data) {
        Matrix nextMatrix = createMatrix(dimension);
        if (nextMatrix.data)
        {
            std::cout << "\nEnter Matrix 1: \n";
            inputMatrix(result);
            for (int index = 2; index <= numberOfMatrix; index++)
            {
                std::cout << "\nEnter Matrix " << index << ": \n";
                inputMatrix(nextMatrix);
                addMatricesInPlace(result, nextMatrix);
            }
            deleteMatrix(nextMatrix);
        }
        else 
        {
            deleteMatrix(result);
            result = nextMatrix;
        }
    }
    return result;
}

Matrix multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2) {
    MatrixDimension resultDimension = {matrix1.dimension.rows, matrix2.dimension.cols};
    Matrix result = createMatrix(resultDimension);
    if (result.data) {
        for (int rowIndex = 0; rowIndex < matrix1.dimension.rows; rowIndex++)
        {
            for (int colIndex = 0; colIndex < matrix2.dimension.cols; colIndex++)
            {
                for (int commonIndex = 0; commonIndex < matrix2.dimension.rows; commonIndex++)
                {
                    *(*(result.data + rowIndex) + colIndex) += 
                        *(*(matrix1.data + rowIndex) + commonIndex) * 
                        *(*(matrix2.data + commonIndex) + colIndex);
                }
            }
        }
    }
    
    return result;
}

bool updateAccumulatedProduct(Matrix& result, Matrix& nextMatrix) {
    Matrix tempResult = multiplyMatrices(result, nextMatrix);
    deleteMatrix(nextMatrix);
    
    if (!tempResult.data) {
        deleteMatrix(result);
        result = tempResult;
        return false;
    }
    
    deleteMatrix(result);
    result = tempResult;
    return true;
}

Matrix multiplyMultipleMatrices(MatrixDimension* dimensions, int numberOfMatrix) {
    Matrix result = createMatrix(dimensions[0]);
    if (result.data) {
        std::cout << "\nEnter Matrix 1: \n";
        inputMatrix(result);

        for (int index = 1; index < numberOfMatrix; index++)
        {
            Matrix nextMatrix = createMatrix(dimensions[index]);
            if (!nextMatrix.data) {
                deleteMatrix(result);
                result = nextMatrix;
                break;
            }

            std::cout << "\nEnter Matrix " << index + 1 << ": \n";
            inputMatrix(nextMatrix);

            if (!updateAccumulatedProduct(result, nextMatrix))
            {
                break;
            }
        }
    }

    return result;
}