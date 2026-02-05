#include <iostream>

class IDGenerator
{
private:
    static int nextID;

public:
    static int getNextID(); 
};

int IDGenerator::nextID = 1;

int IDGenerator::getNextID() { 
    return nextID++; 
}

int main()
{
    for (int count{ 0 }; count < 5; ++count)
        std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';

    return 0;
}