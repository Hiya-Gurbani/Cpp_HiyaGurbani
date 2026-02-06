#include "Matrix.h"
#include "Constants.h"
#include <iomanip>
#include <iostream>

//Constructors
Matrix::Matrix() 
: data{nullptr}, rows{0}, cols{0}{

}

Matrix::Matrix(int currRows, int currCols)
: rows{currRows}, cols{currCols} {
    data = new double*[rows];
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        data[rowIndex] = new double[cols]{};
    }
}

Matrix::Matrix(const Matrix& matrix) 
: Matrix{matrix.rows, matrix.cols}{
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            data[rowIndex][colIndex] = matrix.data[rowIndex][colIndex];
        }
    }
}

//Destructors
Matrix::~Matrix() {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        delete[] data[rowIndex];
    }
    delete[] data;
}

int Matrix::getRows() {
    return rows;
}

int Matrix::getCols() {
    return cols;
}

void Matrix::setMatrixElement(double value, int row, int col) {
    data[row][col] = value;
}

void Matrix::displayMatrix() {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            //Check here
            std::cout << std::setw(Constants::COLUMN_WIDTH) << data[rowIndex][colIndex] << " ";
        }
        std::cout << Constants::LINE_SPACE;
    }
}

//Operator Overloading
Matrix& Matrix::operator+=(const Matrix& sourceMatrix) {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            data[rowIndex][colIndex] += sourceMatrix.data[rowIndex][colIndex];
        }
    }

    return *this;
}

Matrix Matrix::operator*(const Matrix& matrix2) {
    Matrix result(rows, matrix2.cols);

    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < matrix2.cols; colIndex++)
        {
            for (int commonIndex = 0; commonIndex < matrix2.rows; commonIndex++)
            {
                result.data[rowIndex][colIndex] += 
                data[rowIndex][commonIndex] * 
                matrix2.data[commonIndex][colIndex];
            }
        }
    }

    return result;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other)
    {
        return *this;
    }

    for (int index = 0; index < rows; index++)
    {
        delete[] data[index];
    }
    delete[] data;

    rows = other.rows;
    cols = other.cols;
    data = new double*[rows];
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        data[rowIndex] = new double[cols]{};
    }

    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            data[rowIndex][colIndex] = other.data[rowIndex][colIndex];
        }
    }

    return *this;
}
