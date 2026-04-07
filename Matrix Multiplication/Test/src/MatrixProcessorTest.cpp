#include "../inc/MatrixProcessorTest.h"

TEST_F(GivenMatrixProcessorTest, WhenUserChoosesToExit_ThenProgramEnds) {
    EXPECT_CALL(mockInputHandler, inputDimension())
        .Times(4)
        .WillRepeatedly(::testing::Return(2));

    double counter = 1.0;
    EXPECT_CALL(mockInputHandler, inputElement())
        .Times(8)
        .WillRepeatedly([&]() {
            return counter++;
        });

    EXPECT_CALL(mockInputHandler, inputChoice())
        .WillOnce(::testing::Return('n'));

    matrixProcessor->executeProgram();
}

TEST_F(GivenMatrixProcessorTest, WhenInvalidDimensionsEntered_ThenAsksAgain) {
    std::vector<int> values = {2, 2, 3, 3, 2, 2};
    int index = 0;

    EXPECT_CALL(mockInputHandler, inputDimension())
        .Times(values.size())
        .WillRepeatedly([&]() {
            return values.at(index++);
        });

    double counter = 1.0;
    EXPECT_CALL(mockInputHandler, inputElement())
        .Times(8)
        .WillRepeatedly([&]() {
            return counter++;
        });

    EXPECT_CALL(mockInputHandler, inputChoice())
        .WillOnce(::testing::Return('n'));

    matrixProcessor->executeProgram();
}

TEST_F(GivenMatrixProcessorTest, WhenUserChoosesToContinue_ThenRunsTwice) {
    EXPECT_CALL(mockInputHandler, inputDimension())
        .Times(8)
        .WillRepeatedly(::testing::Return(1));

    double counter = 1.0;
    EXPECT_CALL(mockInputHandler, inputElement())
        .Times(4)
        .WillRepeatedly([&]() {
            return counter++;
        });

    EXPECT_CALL(mockInputHandler, inputChoice())
        .WillOnce(::testing::Return('y'))
        .WillOnce(::testing::Return('n'));

    matrixProcessor->executeProgram();
}
