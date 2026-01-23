#include <iostream>
#include <array>

#define ROW_SIZE 5
#define COL_SIZE 2

void printArray(const std::array<std::array<int, COL_SIZE>, ROW_SIZE> &array)
{
    for (const auto& currentRow: array)   
    {
        for (const auto& element: currentRow) 
            std::cout << element << ' ';

        std::cout << '\n';
    }
}

int main()
{
    std::array<std::array<int, COL_SIZE>, ROW_SIZE>  array {{
        {1, 2},
        {5, 6},
        {9, 10},
        {13, 14},
        {17, 18}}};

    printArray(array);

    std::cout << "Rows: " << array.size() << "\n";
    std::cout << "Columns: " << array[0].size() << "\n";

    return 0;
}