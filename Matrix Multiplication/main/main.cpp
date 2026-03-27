#include "Matrix.h"
#include <iostream>

int main() {
    int rows1, cols1;

    std::cout << "MATRIX MULTIPLICATION";
    std::cout << "Enter number of rows of matrix 1: ";
    std::cin >> rows1;

    std::cout << "Enter number of cols of matrix 1: ";
    std::cin >> cols1;

    std::cout << "Enter number of rows of matrix 2: ";
    std::cin >> rows2;

    if (cols1 != rows2)
    {
        std::cout << "The columns of matrix 1 should be equal to rows of matrix 2\n";
        return 0;
    }

    std::cout << "Enter number of cols of matrix 2: ";
    std::cin >> cols2;

    Matrix matrix1(rows1, cols1);
    std::cout << "Enter values of Matrix 1: "
    for (int rowIndex = 0; rowIndex < rows1; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols1; colIndex++)
        {
            std::cout << "Matrix1[" + rowIndex + "][" + colIndex + "]";
            double element;
            std::cin >> element;
            matrix1.setValue(rowIndex, colIndex, element);
        }
    }

    Matrix matrix2(rows2, cols2);
    std::cout << "Enter values of Matrix 2: "
    for (int rowIndex = 0; rowIndex < rows2; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols2; colIndex++)
        {
            std::cout << "Matrix2[" + rowIndex + "][" + colIndex + "]";
            double element;
            std::cin >> element;
            matrix1.setValue(rowIndex, colIndex, element);
        }
    }

    Matrix result = matrix1*(matrix2);

    for (int rowIndex = 0; rowIndex < rows1; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols2; colIndex++)
        {
            std::cout << getValue(rowIndex, colIndex);
        }
    }

}