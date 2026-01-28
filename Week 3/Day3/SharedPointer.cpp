#include <iostream>
#include <memory>

int main()
{
    int value = 42;
    std::shared_ptr<int> pointer1 = std::make_shared<int>(value);

    std::cout << *pointer1 << "\n";   

    std::shared_ptr<int> pointer2 = pointer1;  
    //use_count: tells number of shared owners
    std::cout << pointer1.use_count() << "\n";
    std::cout << pointer2.use_count() << "\n";  

    pointer1.reset();
    std::cout << pointer1.use_count() << "\n"; //Becomes 0 as it doesn't own anything
    if (!pointer1)
    {
        std::cout << "Pointer 1 is now null\n"; 
    }

    std::cout << *pointer2 << "\n";   
}
