#include "../inc/MatrixProcessor.h"
#include "../inc/InputHandler.h"

std::pair<int, int> MatrixProcessor::inputMatrixDimension() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";         
    rows = InputHandler::inputValue();

    std::cout << "Enter the number of columns: ";
    cols = InputHandler::inputValue();

    return {rows, cols};
}

void MatrixProcessor::inputMatrix(Matrix& matrix, int rows, int cols) {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            std::cout << "Matrix[" << rowIndex << "][" << colIndex << "]";
            double element;
            std::cin >> element;
            matrix.setValue(rowIndex, colIndex, element);
        }
    }
}

void MatrixProcessor::displayMatrix(const Matrix& result, int rows, int cols) {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            std::cout << result.getValue(rowIndex, colIndex);
        }
    }
}

void MatrixProcessor::performMatrixMultiplication() {
    std::cout << "Matrix 1 Dimensions: ";
    auto [rows1, cols1] = inputMatrixDimensions();

    int rows2, cols2;
    do
    {
        std::tie(rows2, cols2) = inputMatrixDimension();
        if (cols1 != rows2)
        {
            Logger::printMessage(Constants::MSG_INVALID_DIMENSIONS);
        }
    } while (cols1 != rows2);

    std::cout << "Enter values of Matrix 1: ";
    Matrix matrix1(rows1, cols1);
    inputMatrix(matrix1, rows1, cols1);

    std::cout << "Enter values of Matrix 2: ";
    Matrix matrix2(rows2, cols2);
    inputMatrix(matrix2, rows2, cols2);

    Matrix result = matrix1*(matrix2);
    displayMatrix(result, rows1, cols2);
}

void MatrixProcessor::executeProgram() {
    std::cout << "MATRIX MULTIPLICATION\n";
    
    while (true) {
        performMatrixMultiplication();

        std::cout << "Do you want to multiply another set of matrices (y/n): ";
        char choice = InputHandler::getChoice();
            
        if (choice == Constants::CHOICE_NO || choice == Constants::CHOICE_NO_UPPER)
        {
            Logger::printMessage(Constants::MSG_EXITING_PROGRAM);
            break;
        }   
    }
}
