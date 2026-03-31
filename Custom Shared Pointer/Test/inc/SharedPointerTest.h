#ifndef SHARED_POINTER_TEST_H
#define SHARED_POINTER_TEST_H

#include <gtest/gtest.h>
#include "../../inc/SharedPointer.h"

class GivenSharedPointerTest : public ::testing::Test {
protected:
    SharedPointer<int> defaultPointer;        
    SharedPointer<int> intPointer;            
    
    void SetUp() override {
        intPointer = SharedPointer<int>(new int(42));
    }
};

#endif
