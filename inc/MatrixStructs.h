#ifndef MATRIX_STRUCTS_H
#define MATRIX_STRUCTS_H

struct MatrixDimension {
    int rows;
    int cols;
};

struct Matrix {
    double** data;
    MatrixDimension dimension;
};

#endif 
