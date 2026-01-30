#include <iostream>
#include <cstring>  

int main() {
    const char* original = "String Literal!";
    
    int length = std::strlen(original);
    char* dynamicString = new char[length + 1];
    
    std::strcpy(dynamicString, original);
    
    std::cout << "Dynamically allocated string: " << dynamicString << "\n";
    
    delete[] dynamicString;
    
    return 0;
}
