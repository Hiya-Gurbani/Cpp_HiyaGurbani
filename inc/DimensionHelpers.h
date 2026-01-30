#ifndef DIMENSION_HELPERS_H
#define DIMENSION_HELPERS_H

struct MatrixDimension {
    int rows;
    int cols;
};

void getDimensions(int& matrixRows, int& matrixColumns);
MatrixDimension* getMultipleDimensions(int numberOfMatrix);
bool areDimensionsValid(MatrixDimension* matricesDimensions, int numberOfMatrix);
MatrixDimension* inputValidatedDimensions(int numberOfMatrices);

#endif