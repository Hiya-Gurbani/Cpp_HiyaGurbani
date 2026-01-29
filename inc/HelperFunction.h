#ifndef HELPER_FUNCTION_H
#define HELPER_FUNCTION_H

struct MatrixDimension;

void printMenu();

void getMatrixDimensions(int& matrixRows, int& matrixColumns);
MatrixDimension* getMatricesDimensions(int numberOfMatrix);
bool areDimensionsValid(MatrixDimension* matricesDimensions, int numberOfMatrix);
MatrixDimension* inputMatrixDimensions(int numberOfMatrices);

//Matrix Helpers
double** allocateMatrix(int matrixRows, int matrixColumns);
void inputMatrix(double** matrix, int matrixRows, int matrixColumns);
void displayMatrix(double** array, int matrixRows, int matrixColumns);
void deleteMatrix(double** matrix, int matrixRows);

#endif