#include "DimensionHelpers.h"
#include "Constants.h"
#include "Input.h"
#include "MatrixStructs.h"
#include <iostream>

MatrixDimension getDimensions() {
    MatrixDimension dimension;
    std::cout << "\nEnter the number of rows: ";
    dimension.rows = inputValue(MIN_DIMENSION, MAX_DIMENSION);

    std::cout << "Enter the number of columns: ";
    dimension.cols = inputValue(MIN_DIMENSION, MAX_DIMENSION);

    return dimension;
}

MatrixDimension* getValidMultipleDimensions(int numberOfMatrix) {
    MatrixDimension* dimensions = new MatrixDimension[numberOfMatrix];

    std::cout << "\nMatrix 1 dimensions:\n";
    dimensions[0] = getDimensions();

    for (int index = 1; index < numberOfMatrix; index++) {
        bool isValid = false;
        while (!isValid)
        {
            std::cout << "\nMatrix " << index + 1 << " dimensions: \n";
            std::cout << "Note: Rows must be equal to " << dimensions[index - 1].cols << " \n";
            dimensions[index] = getDimensions();

            if (dimensions[index].rows == dimensions[index - 1].cols)
            {
                isValid = true;
            }
            else
            {
                std::cout << "Error: Matrix " << index + 1 << " must have "
                          << dimensions[index - 1].cols << " rows. Try again.\n";
            }
        }
    }

    return dimensions;
}