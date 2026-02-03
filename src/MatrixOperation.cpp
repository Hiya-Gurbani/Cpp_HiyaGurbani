#include "MatrixOperation.h"
#include "Input.h"
#include "MatrixStruct.h"
#include "MatrixUtil.h"
#include <iostream>

Matrix& addMatricesInPlace(Matrix& result, const Matrix& matrix) {
    for (int rowIndex = 0; rowIndex < result.dimension.rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < result.dimension.cols; colIndex++)
        {
            *(*(result.data + rowIndex) + colIndex) += 
                                    *(*(matrix.data + rowIndex) + colIndex);
        }
    }

    return result;
}

Matrix addMultipleMatrices(int numberOfMatrices, MatrixDimension dimension) {
    Matrix result = createMatrix(dimension);
    if (result.data) {
        Matrix nextMatrix = createMatrix(dimension);
        if (nextMatrix.data)
        {
            std::cout << "\nEnter Matrix 1: \n";
            inputMatrix(result);
            for (int index = 2; index <= numberOfMatrices; index++)
            {
                std::cout << "\nEnter Matrix " << index << ": \n";
                inputMatrix(nextMatrix);
                addMatricesInPlace(result, nextMatrix);
            }
            deleteMatrix(nextMatrix);
        }
        else 
        {
            deleteMatrix(result);
            result = nextMatrix;
        }
    }
    return result;
}

Matrix multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2) {
    MatrixDimension resultDimension = {matrix1.dimension.rows, matrix2.dimension.cols};
    Matrix result = createMatrix(resultDimension);
    if (result.data) {
        for (int rowIndex = 0; rowIndex < matrix1.dimension.rows; rowIndex++)
        {
            for (int colIndex = 0; colIndex < matrix2.dimension.cols; colIndex++)
            {
                for (int commonIndex = 0; commonIndex < matrix2.dimension.rows; commonIndex++)
                {
                    *(*(result.data + rowIndex) + colIndex) += 
                        *(*(matrix1.data + rowIndex) + commonIndex) * 
                        *(*(matrix2.data + commonIndex) + colIndex);
                }
            }
        }
    }
    
    return result;
}

bool updateAccumulatedProduct(Matrix& product, Matrix& nextMatrix) {
    bool isSuccessful = true;

    Matrix tempProduct = multiplyMatrices(product, nextMatrix);
    deleteMatrix(nextMatrix);
    if (!tempProduct.data) {
        deleteMatrix(product);
        product = tempProduct;
        isSuccessful = false;
    }
    
    deleteMatrix(product);
    product = tempProduct;
    return isSuccessful;
}

Matrix multiplyMultipleMatrices(MatrixDimension* dimensions, int numberOfMatrices) {
    Matrix product = createMatrix(dimensions[0]);
    if (product.data) {
        std::cout << "\nEnter Matrix 1: \n";
        inputMatrix(product);

        for (int index = 1; index < numberOfMatrices; index++)
        {
            Matrix nextMatrix = createMatrix(dimensions[index]);
            if (!nextMatrix.data) {
                deleteMatrix(product);
                product = nextMatrix;
                break;
            }

            std::cout << "\nEnter Matrix " << index + 1 << ": \n";
            inputMatrix(nextMatrix);

            if (!updateAccumulatedProduct(product, nextMatrix))
            {
                break;
            }
        }
    }

    return product;
}