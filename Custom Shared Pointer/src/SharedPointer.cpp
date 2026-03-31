template <typename Type, typename Deleter>
void SharedPointer<Type, Deleter>::releaseSharedPointer() {
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

template <typename Type, typename Deleter>
SharedPointer<Type, Deleter>::SharedPointer(const SharedPointer& otherPointer)
: pointer(otherPointer.pointer), referenceCount(otherPointer.referenceCount)
, deleter(otherPointer.deleter) {
    if (referenceCount)
    {
        (*referenceCount)++;
    }
}

template <typename Type, typename Deleter>
SharedPointer<Type, Deleter>::SharedPointer(SharedPointer&& otherPointer) noexcept: 
pointer(otherPointer.pointer), referenceCount(otherPointer.referenceCount)
, deleter(otherPointer.deleter) {
    otherPointer.pointer = nullptr;
    otherPointer.referenceCount = nullptr;
    otherPointer.deleter = Deleter{};
}

template <typename Type, typename Deleter>
SharedPointer<Type, Deleter>& SharedPointer<Type, Deleter>::operator=(const SharedPointer& otherPointer) {
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

template <typename Type, typename Deleter>
SharedPointer<Type, Deleter>& SharedPointer<Type, Deleter>::operator=(SharedPointer&& otherPointer) {
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

template <typename Type, typename Deleter>
void SharedPointer<Type, Deleter>::reset(Type* newPointer) {
    releaseSharedPointer();
    pointer = newPointer;
    referenceCount = newPointer ? new int(1) : nullptr;
    deleter = Deleter{};
}
