#include <iostream>

int main()
{
    int x = 5;          
    const int& ref = x; // This Works

    std::cout << ref << '\n';
    // ref = 7; Error : We can't modify value via const ref                 

    x = 6; //We can modify via the var as it is non-const      

    return 0;
}