#include <iostream>

int main() {
    int array[5] = {1,2, 3, 4, 5};

    for (std::string x : array) //Error coversion from int to non-scaler string
    {
        std::cout << x;
    }
}