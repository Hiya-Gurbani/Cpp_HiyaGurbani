#ifndef DIMENSION_HELPERS_H
#define DIMENSION_HELPERS_H

struct MatrixDimension;

MatrixDimension getDimensions();
MatrixDimension getValidNextDimension(int matrixIndex, int requiredRows);
MatrixDimension* getValidMultipleDimensions(int numberOfMatrix);

#endif