#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

struct MatrixDimension;
struct Matrix;

Matrix createMatrix(MatrixDimension dimension);
void deleteMatrix(Matrix& matrix);

void inputMatrix(Matrix& matrix);
void displayMatrix(const Matrix& matrix);

#endif