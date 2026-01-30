#include "AllHeaders.h"

MatrixDimension getDimensions() {
    MatrixDimension dimension;
    std::cout << "\nEnter the number of rows: ";
    inputValue(dimension.rows);

    std::cout << "Enter the number of columns: ";
    inputValue(dimension.cols);

    return dimension;
}

MatrixDimension* getMultipleDimensions(int numberOfMatrix) {
    MatrixDimension* dimensions = new MatrixDimension[numberOfMatrix];

    for (int index = 0; index < numberOfMatrix; index++) {
        std::cout << "\nMatrix " << index + 1 << " dimensions:";
        dimensions[index] = getDimensions();
    }

    return dimensions;
}

bool areDimensionsValid(MatrixDimension* dimensions, int numberOfMatrix) {
    for (int index = 1; index < numberOfMatrix; index++)
    {
        if (dimensions[index - 1].cols != dimensions[index].rows)
        {
            std::cout << "\nError: Invalid dimensions for multiplication.\n";
            std::cout << "Matrix " << index << " has " << dimensions[index - 1].cols 
            << " columns but Matrix " << index + 1 << " has " 
            << dimensions[index - 1].cols << " rows.\n";
            return false;
        }
    }
    return true;
}

MatrixDimension* inputValidatedDimensions(int numberOfMatrices) {
    MatrixDimension* dimensions = nullptr;
    do {
        if (dimensions != nullptr)
        {
            delete[] dimensions;
        }

        std::cout << "\nMatrix Multiplication Requirement:\n"
                    "The number of columns in each matrix must be "
                    "equal to rows of next matrix.\n";

        dimensions = getMultipleDimensions(numberOfMatrices);
    } while (!areDimensionsValid(dimensions, numberOfMatrices));

    return dimensions;
}