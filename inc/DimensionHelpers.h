#ifndef DIMENSION_HELPERS_H
#define DIMENSION_HELPERS_H

struct MatrixDimension;

MatrixDimension inputDimension();
MatrixDimension inputValidNextDimension(int matrixIndex, int requiredRows);
MatrixDimension* inputValidDimensions(int numberOfMatrix);

#endif