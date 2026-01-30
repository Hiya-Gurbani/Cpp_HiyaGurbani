#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

struct MatrixDimension;
struct Matrix;

Matrix createMatrix(MatrixDimension dimension);
void deleteMatrix(Matrix& matrix);

void inputMatrix(Matrix& matrix);
void displayMatrix(const Matrix& matrix);

void addMatricesInPlace(Matrix& result, const Matrix& matrix);
Matrix addMultipleMatrices(int numberOfMatrix, MatrixDimension dimension);

Matrix multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2);
Matrix multiplyMultipleMatrices(MatrixDimension* dimension, int numberOfMatrix);

#endif