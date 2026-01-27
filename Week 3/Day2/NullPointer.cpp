#include <iostream>

void overload(int*) {
    std::cout << "pointer version\n";
}

void overload(int) {
    std::cout << "int version\n"; 
}

int main() {
    // overload(NULL); //Ambiguous : Compilation Error
    // overload(0); //Ambiguous : Prefers int but if not int func than calls ptr

    overload(nullptr);
}
