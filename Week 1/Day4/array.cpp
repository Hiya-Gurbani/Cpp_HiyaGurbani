#include <iostream>
#include <array>

int main() {
    std::array<int, 5> array{};

    int size = 5;
    //Use const int size = 5 || constexpr int size = 5
    //std::array<int, size> array1{}; //Error as size is not constant

    std::array<int, 2> array1; //Default initialized
    std::cout << array1[0] << " ";

    std::array<int, 2> array2; //Value initialized (to 0)
    std::cout << array2[0] << " ";

    std::array<int, 3> array3{1, 2} //Rest are value initialized

}