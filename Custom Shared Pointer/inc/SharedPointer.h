#ifndef SHARED_POINTER_H
#define SHARED_POINTER_H

#include "Deleter.h"
#include <functional>

template <typename Type, typename Deleter = DefaultDeleter<Type>>
class SharedPointer {
    Type* pointer;
    int* referenceCount;
    std::function<void(Type*)> deleter;

    void releaseSharedPointer();

public: 
    SharedPointer() : pointer(nullptr), referenceCount(nullptr), deleter(Deleter{}) {}

    explicit SharedPointer(Type* givenPointer) : pointer(givenPointer) 
    , referenceCount(givenPointer ? new int(1) : nullptr), deleter(Deleter{}) {}

    SharedPointer(Type* givenPointer, std::function<void(Type*)> customDeleter)
        : pointer(givenPointer), referenceCount(givenPointer ? new int(1) : nullptr)
        , deleter(customDeleter) {}

    SharedPointer(const SharedPointer& otherPointer);

    SharedPointer(SharedPointer&& otherPointer) noexcept;

    ~SharedPointer() {
        releaseSharedPointer();
    }

    SharedPointer& operator=(const SharedPointer& otherPointer);

    SharedPointer& operator=(SharedPointer&& otherPointer);

    Type* get() {
        return pointer;
    }

    int useCount() {
        return referenceCount ? *referenceCount : 0;
    }

    bool unique() {
        return referenceCount ? (*referenceCount) == 1 : false;
    }

    Type& operator*() {
        return *pointer;
    }

    Type* operator->() {
        return pointer;
    }

    operator bool() const {
        return pointer != nullptr;
    }

    void reset(Type* newPointer = nullptr);
};

#include "../src/SharedPointer.cpp"

#endif
