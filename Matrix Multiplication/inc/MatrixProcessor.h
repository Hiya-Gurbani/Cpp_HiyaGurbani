#ifndef MATRIX_PROCESSOR_H
#define MATRIX_PROCESSOR_H

#include "../inc/IInputHandler.h"
#include "../inc/Matrix.h"
#include <utility>

class MatrixProcessor {
    IInputHandler* inputHandler;

    std::pair<int, int> inputMatrixDimension();
    void inputMatrix(Matrix& matrix, int rows, int cols);
    void displayMatrix(const Matrix& result, int rows, int cols);
    void performMatrixMultiplication();

public: 
    MatrixProcessor(IInputHandler* inputHandler) : inputHandler(inputHandler) {}
    void executeProgram();
};

#endif
