#ifndef MATRIX_STRUCT_H
#define MATRIX_STRUCT_H

struct MatrixDimension {
    int rows;
    int cols;
};

struct Matrix {
    double** data;
    MatrixDimension dimension;
};

#endif 
