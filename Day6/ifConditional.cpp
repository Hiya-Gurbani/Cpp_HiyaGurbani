#include <iostream>

#define PLATFORM_LINUX

int main() {
#if defined(PLATFORM_WINDOWS)
{
    std::cout << "Program running on Windows!" << "\n";
}

#elif defined(PLATFORM_LINUX)
    std::cout << "Program running on Linux!" << "\n";

#else
    std::cout << "Program running on Mac!" << "\n";

#endif
}