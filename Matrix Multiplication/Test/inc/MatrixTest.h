#ifndef MATRIX_TEST_H
#define MATRIX_TEST_H

#include "../../inc/Matrix.h"
#include <gtest/gtest.h>

class GivenMatrixTest : public ::testing::Test {
protected:
    Matrix matrix1;
    Matrix matrix2;

    void SetUp() override {
        matrix1 = Matrix(2, 2);
        matrix2 = Matrix(2, 2);

        matrix1.setValue(0, 0, 1.0);
        matrix1.setValue(0, 1, 2.0);
        matrix1.setValue(1, 0, 3.0);
        matrix1.setValue(1, 1, 4.0);

        matrix2.setValue(0, 0, 5.0);
        matrix2.setValue(0, 1, 6.0);
        matrix2.setValue(1, 0, 7.0);
        matrix2.setValue(1, 1, 8.0);
    }
};

#endif
