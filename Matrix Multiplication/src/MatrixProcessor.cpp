#include "../inc/MatrixProcessor.h"
#include "../inc/Constants.h"
#include "../inc/InputHandler.h"
#include "../inc/Logger.h"
#include <iomanip>

std::pair<int, int> MatrixProcessor::inputMatrixDimension() {
    int rows, cols;
    Logger::printMessage(Constants::MSG_INPUT_ROWS);       
    rows = InputHandler::inputDimension();

    Logger::printMessage(Constants::MSG_INPUT_COLS);
    cols = InputHandler::inputDimension();

    return {rows, cols};
}

void MatrixProcessor::inputMatrix(Matrix& matrix, int rows, int cols) {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            Logger::printMessage(Constants::MSG_MATRIX + Constants::OPEN_BRACKET
                + std::to_string(rowIndex) + Constants::CLOSE_BRACKET 
                + Constants::OPEN_BRACKET + std::to_string(colIndex) 
                + Constants::CLOSE_BRACKET + Constants::COLON + Constants::WHITESPACE);
            double element = InputHandler::inputElement();
            matrix.setValue(rowIndex, colIndex, element);
        }
    }
}

void MatrixProcessor::displayMatrix(const Matrix& result, int rows, int cols) {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            Logger::printMatrixElement(result.getValue(rowIndex, colIndex));
        }
        Logger::printMessage(Constants::MSG_NEW_LINE);
    }
}

void MatrixProcessor::performMatrixMultiplication() {
    Logger::printMessage(Constants::MSG_MATRIX1_DIMENSION);
    auto [rows1, cols1] = inputMatrixDimension();
    Logger::printMessage(Constants::MSG_NOTE + Constants::MSG_MULTIPLICATION_NOTE);

    int rows2, cols2;
    do
    {
        Logger::printMessage(Constants::MSG_MATRIX2_DIMENSION);
        std::tie(rows2, cols2) = inputMatrixDimension();
        if (cols1 != rows2)
        {
            Logger::printMessage(Constants::MSG_INVALID_DIMENSIONS + Constants::MSG_MULTIPLICATION_NOTE
                + Constants::MSG_ENTER_AGAIN);
        }
    } while (cols1 != rows2);

    Logger::printMessage(Constants::MSG_INPUT_MATRIX1_VALUES);
    Matrix matrix1(rows1, cols1);
    inputMatrix(matrix1, rows1, cols1);

    Logger::printMessage(Constants::MSG_INPUT_MATRIX2_VALUES);
    Matrix matrix2(rows2, cols2);
    inputMatrix(matrix2, rows2, cols2);

    Matrix result = matrix1*(matrix2);
    Logger::printMessage(Constants::MSG_RESULTANT_MATRIX);
    displayMatrix(result, rows1, cols2);
}

void MatrixProcessor::executeProgram() {
    Logger::printMessage(Constants::MSG_MATRIX_MULTIPLICATION);
    
    while (true) {
        performMatrixMultiplication();

        char choice = InputHandler::getChoice();
            
        if (choice == Constants::CHOICE_NO)
        {
            Logger::printMessage(Constants::MSG_EXITING_PROGRAM);
            break;
        }   
    }
}
