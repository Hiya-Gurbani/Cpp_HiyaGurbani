#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
    double** data;
    int rows;
    int cols;

public:
    Matrix();
    Matrix(int currRows, int currCols);
    Matrix(const Matrix& matrix);

    ~Matrix();

    int getRows();
    int getCols();

    void setMatrixElement(double value, int row, int col);
    void displayMatrix();

    Matrix& operator+=(const Matrix& sourceMatrix);
    Matrix operator*(const Matrix& other);
    Matrix& operator=(const Matrix& other);
};

#endif