#ifndef MATRIX_PROCESSOR_H
#define MATRIX_PROCESSOR_H

#include "../inc/Matrix.h"
#include <utility>

class MatrixProcessor {
    std::pair<int, int> inputMatrixDimension();
    void inputMatrix(Matrix& matrix, int rows, int cols);
    void displayMatrix(const Matrix& result, int rows, int cols);
    void performMatrixMultiplication();

public: 
    void executeProgram();
};

#endif
