#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    double** data;
    int rows;
    int cols;

    double** allocateMatrix();
    void deallocateMatrix();
    void copyMatrixData(const Matrix& sourceMatrix);

public:
    Matrix();
    Matrix(int currRows, int currCols);
    Matrix(const Matrix& sourceMatrix);

    ~Matrix();

    int getRows() {
        return rows;
    };

    int getCols() {
        return cols;
    }

    void setMatrixElement(int row, int col, double value) {
        data[row][col] = value;
    }
    
    void displayMatrix();

    Matrix& operator+=(const Matrix& rhsMatrix);
    Matrix operator*(const Matrix& rhsMatrix);
    Matrix& operator=(const Matrix& sourceMatrix);
};

#endif
