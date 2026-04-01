#include "../inc/MatrixProcessorTest.h"

TEST_F(GivenMatrixProcessorTest, WhenUserChoosesToExit_ThenProgramEnds) {
    EXPECT_CALL(mockInputHandler, inputDimension())
        .WillOnce(::testing::Return(2))
        .WillOnce(::testing::Return(2))
        .WillOnce(::testing::Return(2))
        .WillOnce(::testing::Return(2));

    EXPECT_CALL(mockInputHandler, inputElement())
        .WillOnce(::testing::Return(1.0))
        .WillOnce(::testing::Return(2.0))
        .WillOnce(::testing::Return(3.0))
        .WillOnce(::testing::Return(4.0))
        .WillOnce(::testing::Return(5.0))
        .WillOnce(::testing::Return(6.0))
        .WillOnce(::testing::Return(7.0))
        .WillOnce(::testing::Return(8.0));

    EXPECT_CALL(mockInputHandler, inputChoice())
        .WillOnce(::testing::Return('n'));

    matrixProcessor->executeProgram();
}

TEST_F(GivenMatrixProcessorTest, WhenInvalidDimensionsEntered_ThenAsksAgain) {
    EXPECT_CALL(mockInputHandler, inputDimension())
        .WillOnce(::testing::Return(2))
        .WillOnce(::testing::Return(2))

        .WillOnce(::testing::Return(3))  
        .WillOnce(::testing::Return(2))

        .WillOnce(::testing::Return(2))  
        .WillOnce(::testing::Return(2));

    EXPECT_CALL(mockInputHandler, inputElement())
        .WillOnce(::testing::Return(1.0))
        .WillOnce(::testing::Return(2.0))
        .WillOnce(::testing::Return(3.0))
        .WillOnce(::testing::Return(4.0))
        .WillOnce(::testing::Return(5.0))
        .WillOnce(::testing::Return(6.0))
        .WillOnce(::testing::Return(7.0))
        .WillOnce(::testing::Return(8.0));

    EXPECT_CALL(mockInputHandler, inputChoice())
        .WillOnce(::testing::Return('n'));

    matrixProcessor->executeProgram();
}

TEST_F(GivenMatrixProcessorTest, WhenUserChoosesToContinue_ThenRunsTwice) {
    EXPECT_CALL(mockInputHandler, inputDimension())
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(1));

    EXPECT_CALL(mockInputHandler, inputElement())
        .WillOnce(::testing::Return(1.0))
        .WillOnce(::testing::Return(2.0))
        .WillOnce(::testing::Return(3.0))
        .WillOnce(::testing::Return(4.0));

    EXPECT_CALL(mockInputHandler, inputChoice())
        .WillOnce(::testing::Return('y'))
        .WillOnce(::testing::Return('n'));

    matrixProcessor->executeProgram();
}
