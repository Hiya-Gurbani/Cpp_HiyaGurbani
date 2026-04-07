#ifndef MATRIX_H
#define MATRIX_H

#include <memory>
#include <stdexcept>

class Matrix {
    int rows;
    int cols;
    std::unique_ptr<std::unique_ptr<double[]>[]> data;

public:
    Matrix() : rows(0), cols(0), data(nullptr) {}

    Matrix(int rows, int cols);

    double getValue(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols) 
        {
            throw std::out_of_range("Matrix index out of bounds");
        }
        return data[row][col];
    }

    void setValue(int row, int col, double value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols)
        {
            data[row][col] = value;
        }
    }

    Matrix operator*(const Matrix& otherMatrix);
};

#endif
