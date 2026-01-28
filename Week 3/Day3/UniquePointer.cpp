#include <iostream>
#include <memory>

int main()
{
    int value = 42;
    std::unique_ptr<int> pointer1 = std::make_unique<int>(value);

    std::cout << *pointer1 << "\n";   

    // std::unique_ptr<int> pointer2 = pointer1;  Error: No Copying Allowed
    std::unique_ptr<int> pointer2 = std::move(pointer1); // ownership transfer

    if (!pointer1)
    {
        std::cout << "Pointer 1 is now null\n";
    }
        
    std::cout << *pointer2 << "\n";   
}
