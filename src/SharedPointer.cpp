#include "SharedPointer.h"

void SharedPointer::releaseSharedPointer() {
    if (referenceCount != nullptr)
    {
        (*referenceCount)--;
        if (*referenceCount == 0)
        {
            deleter(pointer);
            delete referenceCount;
            pointer = nullptr;        
            referenceCount = nullptr;
        }
    }
}

SharedPointer& SharedPointer::operator=(const SharedPointer& otherPointer) {
    if (this != &otherPointer)
    {
        releaseSharedPointer();

        pointer = otherPointer.pointer;
        referenceCount = otherPointer.referenceCount;
        deleter = otherPointer.deleter;

        if (referenceCount)
        {
            (*referenceCount)++;
        }
    }

    return *this;
}

SharedPointer& SharedPointer::operator=(SharedPointer&& otherPointer) {
    if (this != &otherPointer)
    {
        releaseSharedPointer();

        pointer = otherPointer.pointer;
        referenceCount = otherPointer.referenceCount;
        deleter = otherPointer.deleter;

        otherPointer.pointer = nullptr;
        otherPointer.referenceCount = nullptr;
        otherPointer.deleter = Deleter{};
    }

    return *this;
}

void SharedPointer::reset() {
    releaseSharedPointer();
    pointer = nullptr;
    referenceCount = nullptr;
    deleter = Deleter{};
}

void SharedPointer::reset(Type* newPointer) {
    reset();
    pointer = newPointer;
    referenceCount = newPointer ? new int(1) : nullptr;
    deleter = Deleter{};
}
