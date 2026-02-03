#include "DimensionHelper.h"
#include "Constants.h"
#include "Input.h"
#include "MatrixStruct.h"
#include <iostream>

MatrixDimension inputDimension() {
    MatrixDimension dimension;
    std::cout << "Enter the number of rows: "; 
              
    dimension.rows = inputValue(ROWS);

    std::cout << "Enter the number of columns: ";
    dimension.cols = inputValue(COLUMNS);

    return dimension;
}

MatrixDimension inputValidNextDimension(int matrixIndex, int requiredRows) {
    MatrixDimension dimension;
    bool isValidDimension = false;

    while (!isValidDimension) {
        std::cout << "\nMatrix " << matrixIndex + 1 << " dimensions: \n"
                  << "Note: Rows must be equal to " << requiredRows << " \n";

        dimension = inputDimension();

        if (dimension.rows == requiredRows)
        {
            isValidDimension = true;
        }
        else
        {
            std::cout << "Error: Matrix " << matrixIndex + 1 << " must have "
                      << requiredRows << " rows. Try again.\n";
        }
    }
    return dimension;
}

MatrixDimension* inputValidDimensions(int numberOfMatrices) {
    MatrixDimension* dimensions = new(std::nothrow) MatrixDimension[numberOfMatrices];
    if (dimensions)
    {
        std::cout << "\nMatrix 1 dimensions:\n";
        dimensions[0] = inputDimension();

        for (int index = 1; index < numberOfMatrices; index++) {
            dimensions[index] = inputValidNextDimension(index, dimensions[index - 1].cols);
        }
    }
    else
    {
        std::cerr << "Memory allocation failed! Cannot perform matrix multiplication.\n";
    }

    return dimensions;
}