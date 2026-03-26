#include <iostream>

template <typename T>
class Auto_Ptr {
    T* ptr;

public:
    Auto_Ptr(T* ptr = nullptr) : ptr(ptr) {}

    ~Auto_Ptr() {
        delete ptr;
    }

    // Copy Contructor
    Auto_Ptr(const Auto_Ptr& current) {
        ptr = new T;
        *ptr = *current.ptr;
    }

    // Mpve Constructor
    Auto_Ptr(Auto_Ptr&& current) 
    : ptr(current.ptr)
    {
        current.ptr = nullptr;
    }

    // Copy Assignment
    Auto_Ptr& operator=(const Auto_Ptr& current) {
        if (&current == this)
        {
            return *this;
        }

        delete ptr;

        ptr = new T;
        *ptr = *current.ptr;

        return *this;
    }

    Auto_Ptr& operator=(Auto_Ptr&& current) {
        if (&current == this)
        {
            return *this;
        }

        delete ptr;

        ptr = current.ptr;
        current.ptr = nullptr;

        return *this;
    }

    T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
	bool isNull() const { return ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_Ptr<Resource> generateResource()
{
	Auto_Ptr<Resource> res{new Resource};
	return res; // this return value will invoke the move constructor
}

int main()
{
	Auto_Ptr<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment

	return 0;
}
