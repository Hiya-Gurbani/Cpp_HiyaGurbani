#include "Input.h"
#include "MenuHandlers.h"
#include <iostream>

int main() {
    int choice;

    while (true)
    {
        printMenu();
        std::cout << "\nEnter your choice: ";
        choice = inputValue();

        if (!handleChoice(choice))
        {
            std::cout << "Exiting Program...\n";
            return 0;
        }
    }
}