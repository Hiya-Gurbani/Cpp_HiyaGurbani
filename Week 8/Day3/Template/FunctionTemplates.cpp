#include <iostream>

template <typename T>
T maxValue(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

int main()
{
    std::cout << maxValue(10, 20) << std::endl;           // int
    std::cout << maxValue(3.5, 2.1) << std::endl;         // double
    std::cout << maxValue(std::string("A"), 
                          std::string("B")) << std::endl; // string
}
