#include <iostream>

int main() {
    char character1 = -65; //Signed by default
    unsigned char character2 = -65; //Would wrap around to +ve

    std::cout << (int)character1 << " " << (int)character2 << "\n"; 

    //Signed & Unsigned can't be used with float & double & bool
    //unsigned float value;
    //unsigned bool flag2;

    bool flag1 = -1;
    bool flag2 = 2;
    
    std::cout << flag1 << " " << flag2 << "\n";
}