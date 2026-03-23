#include "Input.h"
#include "MenuHandler.h"
#include <iostream>

int main() {
    int choice;

    while (true)
    {
        printMenu();
        std::cout << "\nEnter your choice: ";
        choice = inputValue(CHOICE);

        if (!handleChoice(choice))
        {
            std::cout << "Exiting Program...\n";
            return 0;
        }
    }
}