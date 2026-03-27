#ifndef MATRIX_PROCESSOR_H
#define MATRIX_PROCESSOR_H

#include <utility>

class MatrixProcessor {

    std::pair<int, int> inputDimension();
    void inputMatrix(Matrix& matrix);
    void displayMatrix(const Matrix& result);
    void performMatrixMultiplication();

public: 
    void executeProgram();
}

#endif
