#include <iostream>

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    int* array = new int[rows * cols];

    for (int rowIndex = 0; rowIndex < rows; ++rowIndex)
    {
        for (int colIndex = 0; colIndex < cols; ++colIndex)
        {
            std::cin >> array[rowIndex * cols + colIndex];
        }
    }

    std::cout << "Matrix is: " << "\n";
    for (int rowIndex = 0; rowIndex < rows; ++rowIndex)
    {
        for (int colIndex = 0; colIndex < cols; ++colIndex)
        {
            std::cout << array[rowIndex * cols + colIndex] << " ";
        }
        std::cout << "\n";
    }

    delete[] array;
}