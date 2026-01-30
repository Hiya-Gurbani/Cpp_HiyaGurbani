#include "AllHeaders.h"

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