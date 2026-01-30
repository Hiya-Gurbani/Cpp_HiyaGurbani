#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

struct MatrixDimension;

double** allocateMatrix(int matrixRows, int matrixColumns);
void inputMatrix(double** matrix, int matrixRows, int matrixColumns);
void displayMatrix(double** matrix, int matrixRows, int matrixColumns);
void deleteMatrix(double** matrix, int matrixRows);

void addMatricesInPlace(double** matrix1, double** matrix2, int matrixRows, int matrixColumns);
double** addMultipleMatrices(int numberOfMatrix, int matrixRows, int matrixColumns);

double** multiplyMatrices(double** matrix1, double** matrix2, int rows, int cols, int common);
double** multiplyMultipleMatrices(MatrixDimension* matrixDimensions, int numberOfMatrix);

#endif