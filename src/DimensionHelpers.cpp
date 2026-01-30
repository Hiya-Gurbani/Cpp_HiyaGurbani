#include "DimensionHelpers.h"
#include "Constants.h"
#include "Input.h"
#include "MatrixStructs.h"
#include <iostream>

MatrixDimension getDimensions() {
    MatrixDimension dimension;
    std::cout << "\nEnter the number of rows: ";
    dimension.rows = inputValue(MIN_ROWS, MAX_ROWS);

    std::cout << "Enter the number of columns: ";
    dimension.cols = inputValue(MIN_COLS, MAX_COLS);

    return dimension;
}

MatrixDimension getValidNextDimension(int matrixIndex, int requiredRows) {
    MatrixDimension dimension;
    bool isValid = false;

    while (!isValid) {
        std::cout << "\nMatrix " << matrixIndex + 1 << " dimensions: \n"
                  << "Note: Rows must be equal to " << requiredRows << " \n";

        dimension = getDimensions();

        if (dimension.cols == requiredRows)
        {
            isValid = true;
        }
        else
        {
            std::cout << "Error: Matrix " << matrixIndex + 1 << " must have "
                      << dimension.cols << " rows. Try again.\n";
        }
    }

    return dimension;
}

MatrixDimension* getValidMultipleDimensions(int numberOfMatrix) {
    MatrixDimension* dimensions = new(std::nothrow) MatrixDimension[numberOfMatrix];
    if (dimensions)
    {
        std::cout << "\nMatrix 1 dimensions:\n";
        dimensions[0] = getDimensions();

        for (int index = 1; index < numberOfMatrix; index++) {
            dimensions[index] = getValidNextDimension(index, dimensions[index - 1].cols);
        }
    }
    else
    {
        std::cerr << "Memory allocation failed! Cannot perform matrix multiplication.\n";
    }

    return dimensions;
}