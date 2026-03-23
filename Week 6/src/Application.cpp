#include "Application.h"
#include "Constants.h"
#include "Logger.h"
#include "ParserFactory.h"
#include "Utility.h"
#include <iostream>

void Application::execute() {
    Logger::printMessage(Constants::MSG_WELCOME);

    while (true)
    {
        std::string filePath = Utility::getFilePath();

        try
        {
            parser = ParserFactory::createParser(filePath);
            Constants::ParsedData data = parser->parse(filePath);
            Utility::displayResults(data);
        }
        catch (const std::exception& error)
        {
            Logger::printMessage(Constants::MSG_ERROR_PREFIX + std::string(error.what()));
        }

        delete parser;
        parser = nullptr;

        char choice = Utility::getUserChoice();

        if (choice == Constants::CHOICE_NO || choice == Constants::CHOICE_NO_UPPER)
        {
            Logger::printMessage(Constants::MSG_EXITING_PROGRAM);
            break;
        }   
    }
}
