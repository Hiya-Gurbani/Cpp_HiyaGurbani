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

template <typename Type>
class GivenSharedPointerTypedTest : public ::testing::Test {
protected:
    SharedPointer<Type> typedPointer;

    void SetUp() override {
        typedPointer = SharedPointer<Type>(new Type());
    }
};

using TestTypes = ::testing::Types<int, double, std::string>;
TYPED_TEST_SUITE(GivenSharedPointerTypedTest, TestTypes);

#endif
