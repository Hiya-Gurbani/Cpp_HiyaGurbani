#include <iostream>

template <typename T>
class UniquePointer {
    T* pointer;

public:
    UniquePointer(T* givenPointer = nullptr) : pointer(givenPointer) {}

    ~UniquePointer() {
        delete pointer;
        pointer = nullptr;
    }

    UniquePointer(const UniquePointer& otherPointer) = delete;
    UniquePointer& operator=(const UniquePointer& otherPointer) = delete;

    UniquePointer(UniquePointer&& otherPointer) noexcept 
    : pointer(otherPointer.pointer) {
        otherPointer.pointer = nullptr;
    }

    UniquePointer& operator=(UniquePointer&& otherPointer) noexcept {
        if (this != &otherPointer)
        {
            delete pointer;

            pointer = otherPointer.pointer;
            otherPointer.pointer = nullptr;
        }

        return *this;
    }

    T& operator*() {
        return *pointer;
    }

    T* operator->() {
        return pointer;
    }

    T* release() {
        T* tempPointer = pointer;
        pointer = nullptr;
        return tempPointer;
    }

    void reset(T* newPointer = nullptr) {
        delete pointer;
        pointer = newPointer;
    }

    T* get() {
        return pointer;
    }

    explicit operator bool() { 
        return pointer != nullptr; 
    }
};

int main() {
    UniquePointer<int> pointer1(new int(32));
    std::cout << *pointer1 << "\n";

    // Copy is deleted as one resource can be owned by one ptr only
    // UniquePointer<int> pointer2 = pointer1; 

    UniquePointer<int> pointer2 = std::move(pointer1);

    if (!pointer1)
    {
        std::cout << "pointer1 is empty now!\n";
    }
    std::cout << *pointer2 << "\n";

    return 0;
}
