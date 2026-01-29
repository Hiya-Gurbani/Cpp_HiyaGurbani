#include <iostream>
#include <limits>
#include "AllHeaders.h"
#include "CoreFunction.h"
#include "HandlerFunction.h"
#include "HelperFunction.h"
#include "ValidationFunction.h"

int main() {
    int choice;

    while (true)
    {
        printMenu();
        std::cout << "\nEnter your choice: ";
        inputValue(choice);

        if (!handleChoice(choice))
        {
            std::cout << "Exiting Program...\n";
            return 0;
        }
    }
}