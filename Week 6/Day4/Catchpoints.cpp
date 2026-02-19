#include <iostream>
#include <stdexcept>

void mayThrow(bool flag) {
    if (flag)
        throw std::runtime_error("Something went wrong");
}

int main() {
    try {
        mayThrow(true);
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}
