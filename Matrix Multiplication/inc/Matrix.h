#ifndef MATRIX_H
#define MATRIX_H

#include <memory>

class Matrix {
    int rows;
    int cols;
    std::unique_ptr<std::unique_ptr<double[]>[]> data;

public:
    Matrix() : rows(0), cols(0), data(nullptr) {}

    Matrix(int rows, int cols);

    double getValue(int row, int col) {
        return data[row][col];
    }

    void setValue(int row, int col, double value) {
        data[row][col] = value;
    }

    Matrix operator*(const Matrix& otherMatrix);
};

#endif
