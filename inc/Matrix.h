#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
    double** data;
    int rows;
    int cols;

    double** allocateMemory();
    void deallocateMemory();
    void copyDataFrom(const Matrix& sourceMatrix);

public:
    Matrix();
    Matrix(int currRows, int currCols);
    Matrix(const Matrix& sourceMatrix);

    ~Matrix();

    int getRows();
    int getCols();

    void setElementAt(double value, int row, int col);
    void displayMatrix();

    Matrix& operator+=(const Matrix& rhsMatrix);
    Matrix operator*(const Matrix& rhsMatrix);
    Matrix& operator=(const Matrix& sourceMatrix);
};

#endif