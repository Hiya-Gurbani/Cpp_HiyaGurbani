#include "Matrix.h"
#include "Constants.h"
#include <iomanip>
#include <iostream>

double** Matrix::allocateMatrix() {
    data = new double*[rows];
    for (int index = 0; index < rows; index++) 
    {
        data[index] = new double[cols]{};  
    }

    return data;
}

void Matrix::deallocateMatrix() {
    if (data != nullptr) 
    {
        for (int index = 0; index < rows; index++) 
        {
            delete[] data[index];
        }
        delete[] data;
        data = nullptr;
    }
}

void Matrix::copyMatrixData(const Matrix& sourceMatrix) {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) 
    {
        for (int colIndex = 0; colIndex < cols; colIndex++) 
        {
            data[rowIndex][colIndex] = sourceMatrix.data[rowIndex][colIndex];
        }
    }
}

Matrix::Matrix() 
    : data{nullptr}, rows{0}, cols{0}{
}

Matrix::Matrix(int currRows, int currCols)
    : rows{currRows}, cols{currCols} , data{nullptr} {
    allocateMatrix();
}

Matrix::Matrix(const Matrix& sourceMatrix) 
    : rows{sourceMatrix.rows}, cols{sourceMatrix.cols}, data{nullptr} {
    allocateMatrix();
    copyMatrixData(sourceMatrix);
}

Matrix::~Matrix() {
    deallocateMatrix();
}

void Matrix::displayMatrix() {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            std::cout << std::setw(Constants::COLUMN_WIDTH) << data[rowIndex][colIndex] 
            << Constants::WHITE_SPACE;
        }
        std::cout << Constants::NEWLINE_SPACE;
    }
}

Matrix& Matrix::operator+=(const Matrix& rhsMatrix) {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            data[rowIndex][colIndex] += rhsMatrix.data[rowIndex][colIndex];
        }
    }

    return *this;
}

Matrix Matrix::operator*(const Matrix& rhsMatrix) {
    Matrix result(rows, rhsMatrix.cols);

    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < rhsMatrix.cols; colIndex++)
        {
            for (int commonIndex = 0; commonIndex < rhsMatrix.rows; commonIndex++)
            {
                result.data[rowIndex][colIndex] += 
                data[rowIndex][commonIndex] * rhsMatrix.data[commonIndex][colIndex];
            }
        }
    }

    return result;
}

Matrix& Matrix::operator=(const Matrix& sourceMatrix) {
    if (this == &sourceMatrix)
    {
        return *this;
    }

    deallocateMatrix();

    rows = sourceMatrix.rows;
    cols = sourceMatrix.cols;
    allocateMatrix();
    copyMatrixData(sourceMatrix);

    return *this;
}
