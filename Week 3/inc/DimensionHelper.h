#ifndef DIMENSION_HELPER_H
#define DIMENSION_HELPER_H

struct MatrixDimension;

MatrixDimension inputDimension();
MatrixDimension inputValidNextDimension(int matrixIndex, int requiredRows);
MatrixDimension* inputValidDimensions(int numberOfMatrix);

#endif