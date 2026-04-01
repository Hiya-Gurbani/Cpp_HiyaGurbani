#ifndef DELETER_H
#define DELETER_H

template <typename Type>
struct DefaultDeleter {
    void operator()(Type* pointer) {
        delete pointer;
    }
};

template <typename Type>
struct ArrayDeleter {
    void operator()(Type* pointer) {
        delete[] pointer;
    } 
};

#endif
