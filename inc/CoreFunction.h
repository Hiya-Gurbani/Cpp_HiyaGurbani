#ifndef CORE_FUNCTION_H
#define CORE_FUNCTION_H

void addMatrices(int** matrix1, int** matrix2, int matrixRows, int matrixColumns);
int** addNMatrices(int numberOfMatrix, int matrixRows, int matrixColumns);

int** multiplyMatrices(int** matrix1, int** matrix2, int rows, int cols, int common);
int** multiplyNMatrices(int** matrixDimensions, int numberOfMatrix);

#endif