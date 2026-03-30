A collection of C++ assignments focusing on smart pointers and memory management.

---

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

---

## Matrix Multiplication

A C++ program that performs matrix multiplication using smart pointers (`std::unique_ptr`) for memory management. Supports any valid matrix dimensions with input validation.

### How to Run

```bash
cd "Matrix Multiplication"
g++ main/main.cpp src/*.cpp -o MatrixMultiplication.out
./MatrixMultiplication.out
```

### Sample Output

```
MATRIX MULTIPLICATION

Matrix 1 Dimensions:
Enter the number of rows: 2
Enter the number of columns: 2
Matrix 2 Dimensions:
Enter the number of rows: 2
Enter the number of columns: 2
Enter values of Matrix 1:
Matrix[0][0]: 1
Matrix[0][1]: 2
Matrix[1][0]: 3
Matrix[1][1]: 4
Enter values of Matrix 2:
Matrix[0][0]: 5
Matrix[0][1]: 6
Matrix[1][0]: 7
Matrix[1][1]: 8
Result:
19    22
43    50
Do you want to multiply another set of matrices (y/n): n
Thank you for using the program!
```
