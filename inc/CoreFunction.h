#ifndef CORE_FUNCTION_H
#define CORE_FUNCTION_H

struct MatrixDimension;

void addMatrices(double** matrix1, double** matrix2, int matrixRows, int matrixColumns);
double** addNMatrices(int numberOfMatrix, int matrixRows, int matrixColumns);

double** multiplyMatrices(double** matrix1, double** matrix2, int rows, int cols, int common);
double** multiplyNMatrices(MatrixDimension* matrixDimensions, int numberOfMatrix);

#endif