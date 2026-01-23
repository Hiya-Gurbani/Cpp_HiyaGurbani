#include <iostream>

#define MAX_VALUE 10

int main() {
    std::cout << MAX_VALUE << "\n";

//#define MAX_VALUE 20 Error: Max_VALUE redefined

#undef MAX_VALUE
#define MAX_VALUE 20

    std::cout << MAX_VALUE << "\n";
}