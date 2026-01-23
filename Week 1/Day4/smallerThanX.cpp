//Count the number of elements strictly smaller than x
//Array cna have +ve and -ve

#include <iostream>
#include <array>

#define SIZE 7

void readArray(std::array<int, SIZE>& array) {
    for (int& element : array)
    {
        std::cin >> element;
    }
}

void printArray(const std::array<int, SIZE>& array) {
    for (int element : array)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

int smallerThanX(const std::array<int, SIZE> array, const int target) {
    int count = 0;
    for (int element : array)
    {
        if (element < target)
        {
            count++;
        }
    }
    return count;
}

int main() {
    std::array<int, SIZE> input;

    readArray(input);
    
    std::cout << "\nEntered Array: \n";
    printArray(input);

    int target;
    std::cin >> target;

    int count = smallerThanX(input, target);
    std::cout << "Number of elements less than " << target << " are: " << count << "\n";
}