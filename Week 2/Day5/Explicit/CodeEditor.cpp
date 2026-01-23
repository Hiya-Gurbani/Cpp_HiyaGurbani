#include <iostream>
#include <dlfcn.h>

namespace editor 
{
    using pluginFunction = void(*)();
}

void* loadLibrary(const char* libraryName) {
    void* handle = dlopen(libraryName, RTLD_LAZY);
    if (!handle)
    {
        std::cerr << "Cannot Load Library: " << dlerror() << "\n";
    }

    return handle;
}

editor::pluginFunction loadFunction(void* handle, const char* pluginName) {
    dlerror();
    editor::pluginFunction operationFunction = 
                            (editor::pluginFunction)dlsym(handle, pluginName);

    char* error = dlerror();
    if (error)
    {
        std::cerr << "Cannot Find Function: " << error << "\n";
        dlclose(handle);
        operationFunction = nullptr;
    }

    return operationFunction;
}

void addPlugin(const char* libraryName, const char* pluginName) {
    void* handle = loadLibrary(libraryName);
    if (!handle)
    {
        exit(0);
    }

    editor::pluginFunction function = loadFunction(handle, pluginName);
    if (!function)
    {
        exit(0);
    }

    function();
    dlclose(handle);
}

int main() {
    std::cout << "\nWelcome to your Code Editor\n";

    std::cout << "Available Plugins to add:\n";
    std::cout << "1. Theme Plugin\n2. AI Support Plugin\n"
                "3. Autocomplete Plugin\n4. Exit\n";

    unsigned int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch(choice) 
    {
        case 1:
            addPlugin("./libtheme.so", "themePlugin");
            break;

        case 2:
            addPlugin("./libaisupport.so", "aiSupportPlugin");
            break;

        case 3:
            addPlugin("./libautocomplete.so", "autoCompletePlugin");
            break;

        default:
            std::cout << "Invalid choice!\n";   
    }

    return 0;
}
