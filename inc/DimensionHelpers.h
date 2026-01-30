#ifndef DIMENSION_HELPERS_H
#define DIMENSION_HELPERS_H

struct MatrixDimension;
struct Matrix;

MatrixDimension getDimensions();
MatrixDimension* getMultipleDimensions(int numberOfMatrix);
bool areDimensionsValid(MatrixDimension* matricesDimensions, int numberOfMatrix);
MatrixDimension* inputValidatedDimensions(int numberOfMatrices);

#endif