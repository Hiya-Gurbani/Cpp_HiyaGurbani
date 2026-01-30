#include "AllHeaders.h"

void getDimensions(int& matrixRows, int& matrixColumns) {
    std::cout << "Enter the number of rows of matrix: ";
    inputValue(matrixRows);

    std::cout << "Enter the number of columns of matrix: ";
    inputValue(matrixColumns);
}

MatrixDimension* getMultipleDimensions(int numberOfMatrix) {
    MatrixDimension* matricesDimensions = new MatrixDimension[numberOfMatrix];

    for (int index = 0; index < numberOfMatrix; index++) {
        std::cout << "Matrix " << index + 1 << ":\n";
        getDimensions(matricesDimensions[index].rows, 
        matricesDimensions[index].cols);
    }

    return matricesDimensions;
}

bool areDimensionsValid(MatrixDimension* matricesDimensions, int numberOfMatrix) {
    for (int index = 1; index < numberOfMatrix; index++)
    {
        if (matricesDimensions[index - 1].cols != matricesDimensions[index].rows)
        {
            std::cout << "Error: Matrices can't be multiplied! Dimensions are invalid.\n";
            return false;
        }
    }
    return true;
}

MatrixDimension* inputValidatedDimensions(int numberOfMatrices) {
    MatrixDimension* matricesDimensions = nullptr;
    do {
        if (matricesDimensions != nullptr)
        {
            delete[] matricesDimensions;
        }
        std::cout << "\nMatrix multiplication rule:\n"
                    "For every consecutive pair, columns of matrix i "
                    "must equal rows of matrix i+1.\n\n";

        matricesDimensions = getMultipleDimensions(numberOfMatrices);
    } while (!areDimensionsValid(matricesDimensions, numberOfMatrices));

    return matricesDimensions;
}