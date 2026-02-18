#include <iostream>
#include <string>

int main()
{
    try
    {
        throw -1; 
    }
    catch (double value) 
    {
        std::cerr << "We caught an exception of type double\n";
    }
    catch (int value)
    {
        std::cerr << "We caught an int exception with value: " << value << '\n';
    }
    catch (const std::string&) 
    {
        std::cerr << "We caught an exception of type std::string\n";
    }

    std::cout << "Continuing on our way\n";

    return 0;
}