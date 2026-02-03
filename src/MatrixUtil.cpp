#include "MatrixUtil.h"
#include "Constants.h"
#include "Input.h"
#include "MatrixStruct.h"
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
    for (int rowIndex = 0; rowIndex < matrix.dimension.rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrix.dimension.cols; colIndex++)
        {
            std::cout << std::setw(COLUMN_WIDTH) << 
            *(*(matrix.data + rowIndex) + colIndex) << " ";
        }
        std::cout << "\n";
    }
}