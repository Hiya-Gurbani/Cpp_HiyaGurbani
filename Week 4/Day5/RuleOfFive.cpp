#include <iostream>
#include <algorithm> 

class Array {
    int* data;
    size_t size;

public:
    Array(size_t s) : size(s) {
        data = new int[size]{};
        std::cout << "Constructor called\n";
    }

    ~Array() {
        delete[] data;
        std::cout << "Destructor called\n";
    }

    Array(const Array& other) : size(other.size) {
        data = new int[size];
        //copy(start of source, end of souce, copying destination start)
        std::copy(other.data, other.data + size, data);
        std::cout << "Copy constructor called\n";
    }

    Array& operator=(const Array& other) {
        if (this == &other) 
        {
            return *this;
        }

        delete[] data; 

        size = other.size;
        data = new int[size];
        std::copy(other.data, other.data + size, data);

        std::cout << "Copy assignment called\n";
        return *this;
    }

    Array(Array&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move constructor called\n";
    }

    Array& operator=(Array&& other) noexcept {
        if (this == &other) return *this;

        delete[] data; 

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        std::cout << "Move assignment called\n";
        return *this;
    }

    void setValue(size_t index, int value) {
        if (index < size) data[index] = value;
    }

    void print(){
        for (size_t i = 0; i < size; ++i)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    Array array1(5);         
    array1.setValue(0, 10);
    array1.setValue(1, 20);

    Array array2 = array1; //Copy constructor      
    Array array3(3);
    array3 = array1; //Assignment (Copying)            

    Array array4 = std::move(array1); //Move constructor
    Array array5(2);
    array5 = std::move(array2); //Assignment (Moving)

    array3.print(); 
    array4.print(); 
    array5.print(); 

    return 0; 
}
