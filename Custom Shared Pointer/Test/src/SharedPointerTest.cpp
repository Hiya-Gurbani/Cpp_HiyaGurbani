#include "../inc/SharedPointerTest.h"
#include "../inc/MockDeleter.h"

TEST_F(GivenSharedPointerTest, WhenCopyConstructorCalled_ThenReferenceCountIncreases) {
    SharedPointer<int> anotherPointer(intPointer);

    EXPECT_EQ(intPointer.useCount(), 2);
    EXPECT_EQ(anotherPointer.useCount(), 2);
    EXPECT_EQ(intPointer.get(), anotherPointer.get());
}

TEST_F(GivenSharedPointerTest, WhenCopyingNullPointer_ThenResultIsAlsoNull) {
    SharedPointer<int> anotherPointer(defaultPointer);

    EXPECT_EQ(anotherPointer.get(), nullptr);
    EXPECT_EQ(anotherPointer.useCount(), 0);
    EXPECT_FALSE(anotherPointer);
}

TEST_F(GivenSharedPointerTest, WhenMoveConstructorCalled_ThenReferenceCountIsSame) {
    SharedPointer<int> anotherPointer(std::move(intPointer));

    EXPECT_EQ(anotherPointer.useCount(), 1);
    EXPECT_EQ(intPointer.get(), nullptr);
    EXPECT_FALSE(intPointer);
}

TEST_F(GivenSharedPointerTest, WhenCopyAssignmentCalled_ThenReferenceCountIncreases) {
    SharedPointer<int> anotherPointer;
    anotherPointer = intPointer;

    EXPECT_EQ(intPointer.useCount(), 2);
    EXPECT_EQ(anotherPointer.useCount(), 2);
    EXPECT_EQ(intPointer.get(), anotherPointer.get());
}

TEST_F(GivenSharedPointerTest, WhenMoveAssignmentCalled_ThenOwnershipIsTransferred) {
    SharedPointer<int> anotherPointer;
    anotherPointer = std::move(intPointer);

    EXPECT_EQ(anotherPointer.useCount(), 1);
    EXPECT_EQ(intPointer.get(), nullptr);
    EXPECT_FALSE(intPointer);
}

TEST_F(GivenSharedPointerTest, WhenSelfAssigned_ThenRefCountUnchanged) {
    intPointer = intPointer;

    EXPECT_EQ(intPointer.useCount(), 1);
    EXPECT_EQ(*intPointer, 42);
}

TEST_F(GivenSharedPointerTest, WhenResetCalled_ThenPointerBecomesNull) {
    intPointer.reset();

    EXPECT_EQ(intPointer.get(), nullptr);
    EXPECT_EQ(intPointer.useCount(), 0);
    EXPECT_FALSE(intPointer);
}

TEST_F(GivenSharedPointerTest, WhenResetCalled_ThenReferenceCountDecreases) {
    SharedPointer<int> anotherPointer(intPointer);  
    EXPECT_EQ(anotherPointer.useCount(), 2);

    intPointer.reset();

    EXPECT_EQ(anotherPointer.useCount(), 1);
    EXPECT_TRUE(anotherPointer.unique());
}

TEST_F(GivenSharedPointerTest, WhenResetWithNewPointerCalled_ThenManagesNewPointer) {
    int* rawPointer = new int(100);
    intPointer.reset(rawPointer);

    EXPECT_EQ(*intPointer, 100);
    EXPECT_EQ(intPointer.useCount(), 1);
}

TEST_F(GivenSharedPointerTest, WhenResetWithNullptr_ThenPointerBecomesNull) {
    intPointer.reset(nullptr);

    EXPECT_EQ(intPointer.get(), nullptr);
    EXPECT_EQ(intPointer.useCount(), 0);
    EXPECT_FALSE(intPointer);
}

TEST_F(GivenSharedPointerTest, WhenPointerIsUnique_ThenUniqueReturnsTrue) {
    EXPECT_TRUE(intPointer.unique());
}

TEST_F(GivenSharedPointerTest, WhenPointerIsShared_ThenUniqueReturnsFalse) {
    SharedPointer<int> anotherPointer(intPointer);

    EXPECT_FALSE(intPointer.unique());
}

TEST_F(GivenSharedPointerTest, WhenPointerIsValid_ThenOperatorBoolReturnsTrue) {
    EXPECT_TRUE(intPointer);
}

TEST_F(GivenSharedPointerTest, WhenPointerIsNull_ThenOperatorBoolReturnsFalse) {
    EXPECT_FALSE(defaultPointer);
}


TEST(GivenSharedPointerDeleterTest, WhenLastOwnerDestroyed_ThenDeleterCalledOnce) {
    MockDeleter mockDeleter;
    EXPECT_CALL(mockDeleter, Call(::testing::_)).Times(1);

    {
        SharedPointer<int> sharedPointer(new int(42), [&mockDeleter](int* param) {
            mockDeleter(param);
        });
    }  
}

TEST(GivenSharedPointerDeleterTest, WhenNotLastOwner_ThenDeleterNotCalled) {
    MockDeleter mockDeleter;
    EXPECT_CALL(mockDeleter, Call(::testing::_)).Times(1); 

    SharedPointer<int> sharedPointer1(new int(42), [&mockDeleter](int* param) {
        mockDeleter(param);
    });
    {
        SharedPointer<int> sharedPointer2(sharedPointer1);
    }  
}      
