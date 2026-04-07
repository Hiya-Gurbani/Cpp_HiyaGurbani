#ifndef MATRIX_PROCESSOR_TEST_H
#define MATRIX_PROCESSOR_TEST_H

#include "../../inc/MatrixProcessor.h"
#include "IMockInputHandler.h"
#include <gtest/gtest.h>

class GivenMatrixProcessorTest : public ::testing::Test {
protected:
    IMockInputHandler mockInputHandler;
    MatrixProcessor* matrixProcessor;

    void SetUp() override {
        matrixProcessor = new MatrixProcessor(mockInputHandler);
    }

    void TearDown() override {
        delete matrixProcessor;
    }
};

#endif
