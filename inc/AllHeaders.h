#ifndef ALL_HEADERS_H
#define ALL_HEADERS_H

#include <iostream>
#include <limits>
#include "DimensionHelpers.h"
#include "Input.h"
#include "MatrixOperations.h"
#include "MenuHandlers.h"

struct MatrixDimension {
    int rows;
    int cols;
};

struct Matrix {
    double** data;
    MatrixDimension dimension;
};

#endif