#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

struct MatrixDimension;
struct Matrix;

void addMatricesInPlace(Matrix& result, const Matrix& matrix);
Matrix addMultipleMatrices(int numberOfMatrix, MatrixDimension dimension);

Matrix multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2);
bool updateAccumulatedProduct(Matrix& product, Matrix& nextMatrix);
Matrix multiplyMultipleMatrices(MatrixDimension* dimension, int numberOfMatrix);

#endif