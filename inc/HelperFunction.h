#ifndef HELPER_FUNCTION_H
#define HELPER_FUNCTION_H

void printMenu();

void getMatrixDimensions(int& matrixRows, int& matrixColumns);
int** getMatricesDimensions(int numberOfMatrix);
bool areDimensionsValid(int** matricesDimensions, int numberOfMatrix);
int** inputMatrixDimensions(int numberOfMatrices);

//Matrix Helpers
int** allocateMatrix(int matrixRows, int matrixColumns);
void inputMatrix(int** matrix, int matrixRows, int matrixColumns);
void displayMatrix(int** array, int matrixRows, int matrixColumns);
void deleteMatrix(int** matrix, int matrixRows);

#endif