#include "../inc/MatrixTest.h"

TEST_F(GivenMatrixTest, WhenMatricesMultiplied_ThenResultIsCorrect) {
    Matrix result = matrix1 * matrix2;

    EXPECT_DOUBLE_EQ(result.getValue(0, 0), 19.0);
    EXPECT_DOUBLE_EQ(result.getValue(0, 1), 22.0);
    EXPECT_DOUBLE_EQ(result.getValue(1, 0), 43.0);
    EXPECT_DOUBLE_EQ(result.getValue(1, 1), 50.0);
}

TEST_F(GivenMatrixTest, WhenMultipliedByIdentityMatrix_ThenResultIsUnchanged) {
    Matrix identity(2, 2);
    identity.setValue(0, 0, 1.0);
    identity.setValue(0, 1, 0.0);
    identity.setValue(1, 0, 0.0);
    identity.setValue(1, 1, 1.0);

    Matrix result = matrix1 * identity;

    EXPECT_DOUBLE_EQ(result.getValue(0, 0), 1.0);
    EXPECT_DOUBLE_EQ(result.getValue(0, 1), 2.0);
    EXPECT_DOUBLE_EQ(result.getValue(1, 0), 3.0);
    EXPECT_DOUBLE_EQ(result.getValue(1, 1), 4.0);
}

TEST_F(GivenMatrixTest, WhenMultipliedByZeroMatrix_ThenResultIsZero) {
    Matrix zeroMatrix(2, 2);
    zeroMatrix.setValue(0, 0, 0.0); 
    zeroMatrix.setValue(0, 1, 0.0);
    zeroMatrix.setValue(1, 0, 0.0); 
    zeroMatrix.setValue(1, 1, 0.0);

    Matrix result = matrix1 * zeroMatrix;

    EXPECT_DOUBLE_EQ(result.getValue(0, 0), 0.0);
    EXPECT_DOUBLE_EQ(result.getValue(0, 1), 0.0);
    EXPECT_DOUBLE_EQ(result.getValue(1, 0), 0.0);
    EXPECT_DOUBLE_EQ(result.getValue(1, 1), 0.0);
}
