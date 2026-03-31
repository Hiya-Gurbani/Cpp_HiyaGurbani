## Custom Shared Pointer

A custom implementation of `std::shared_ptr` in C++ with support for custom deleters, reference counting, and all standard smart pointer operations.

### How to Run

```bash
cd "Custom Shared Pointer"
g++ main/main.cpp src/Logger.cpp -o SharedPointerDemo.out
./SharedPointerDemo.out
```

### Sample Output

```
DOUBLE SECTION
After Create          >> value: 21.3  useCount: 1  unique: yes
After Copy            >> useCount: 2  unique: no
After Move            >> useCount: 2  unique: no
doublePointer2 after move >> null

INT ARRAY SECTION
After Create          >> values: 10 20 30  useCount: 1
After Reset           >> null  useCount: 0

STRING SECTION
After Create          >> value: Hello  length: 5  useCount: 1
After Copy Assignment >> useCount: 2
After Move Assignment >> useCount: 2
stringPointer2 after move >> null

Lambda pointer        >> value: Lambda  useCount: 1
Lambda deleter called for: Lambda
After lambda scope : lambda deleter fired above
```
