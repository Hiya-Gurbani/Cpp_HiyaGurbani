#ifndef MATRIX_UTIL_H
#define MATRIX_UTIL_H

struct MatrixDimension;
struct Matrix;

Matrix createMatrix(MatrixDimension dimension);
void deleteMatrix(Matrix& matrix);

void inputMatrix(Matrix& matrix);
void displayMatrix(const Matrix& matrix);

#endif