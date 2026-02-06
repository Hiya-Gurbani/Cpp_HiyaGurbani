#include "Application.h"
#include "InputHandler.h"
#include "Logger.h"
#include "MenuHandler.h"
#include "Validator.h"
#include <iostream>

void Application::execute() {
    int choice;

    while (true) 
    {
        std::cout << Logger::MSG_OPERATIONS_MENU;
        std::cout << Logger::MSG_INPUT_CHOICE;
        choice = InputHandler::inputValue(CHOICE);

        if (!MenuHandler::handleChoice(choice))
        {
            std::cout << Logger::MSG_PROGRAM_EXIT;
            return;
        }
    }
}