#include <iostream>
using namespace std;
 
int main() {
    int w=10, x=10, y1=10, z=10, z1=10;
    std::cout << w++ + w++ << std::endl;
    std::cout << x++ + ++x << std::endl;
    std::cout << ++y1 + y1++ << std::endl;
    std::cout << ++z + ++z << std::endl;
    std::cout << --z1 - z1-- << std::endl;
}