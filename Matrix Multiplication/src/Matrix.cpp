#include "../inc/Matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data = std::make_unique<std::unique_ptr<double[]>[]>(rows);
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        data[rowIndex] = std::make_unique<double[]>(cols);
    }
}

Matrix Matrix::operator*(const Matrix& otherMatrix) {
    Matrix result(rows, otherMatrix.cols);

    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < otherMatrix.cols; colIndex++)
        {
            for (int commonIndex = 0; commonIndex < cols; commonIndex++)
            {
                result.data[rowIndex][colIndex] += 
                data[rowIndex][commonIndex] * otherMatrix.data[commonIndex][colIndex];
            }
        }
    }
    return result;
}
