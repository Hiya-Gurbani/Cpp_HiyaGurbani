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

### How to Run Tests
```bash
cd "Matrix Multiplication/Test"
cd Test && g++ ../src/*.cpp src/*.cpp main/main.cpp -lgtest -lgmock -lpthread -o MatrixMultiplicationTests.out
./MatrixMultiplicationTests.out
```

### Test Cases

- Matrix multiplication — correct result and identity matrix
- MatrixProcessor — full program flow, invalid dimensions retry, continue and exit
- Validator — parameterized tests for valid (y, n) and invalid choices
