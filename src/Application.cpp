#include "Application.h"
#include "Logger.h"
#include "InputHandler.h"
#include "MenuHandler.h"

void Application::execute() {
    int choice;

    while (true) 
    {
        MenuHandler::printMenu();
        std::cout << Logger::MSG_INPUT_CHOICE;
        choice = InputHandler::inputValue(CHOICE);

        if (!MenuHandler::handleChoice(choice))
        {
            std::cout << Logger::MSG_PROGRAM_EXIT;
            return;
        }
    }
}