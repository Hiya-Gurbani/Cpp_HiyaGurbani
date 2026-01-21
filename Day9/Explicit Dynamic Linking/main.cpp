#include "Plugin.h"
#include <iostream>
#include <dlfcn.h>

int main() {
    void* handle = dlopen("./libplugin.so", RTLD_LAZY);
    if (!handle) 
    {
        std::cerr << "Cannot Load Library: " << dlerror() << "\n";
        return 1;
    }

    dlerror();

    typedef int (*multiply_t)(int, int);
    multiply_t multiply = (multiply_t)dlsym(handle, "multiply");

    char* error = dlerror();
    if (error)
    {
        std::cerr << "Cannot Find Function: " << error << "\n";
        dlclose(handle);
        return 1;
    }

    int result = multiply(5, 6);
    std::cout << result << "\n";
    dlclose(handle);

    return 0;
}