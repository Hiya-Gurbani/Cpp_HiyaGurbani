#include "Utility.h"
#include "Logger.h"
#include "Validator.h"
#include <iostream>

char Utility::getUserChoice() {
    std::string choice;

    while (true)
    {
        Logger::printMessage(Constants::MSG_CONTINUE); 
        std::getline(std::cin, choice);

        if (Validator::isValidChoice(choice))
        {
            break;
        }     
    }

    return choice[0];
}

std::string Utility::getFilePath() {
    std::string path;

    while (true) 
    {
        Logger::printMessage(Constants::MSG_ENTER_FILE_PATH);
        std::getline(std::cin, path);

        if(Validator::isValidFilePath(path)) 
        {
            break;
        }
    }

    return path;
}

void Utility::displayResults(Constants::ParsedData& data) {
    Logger::printMessage(Constants::MSG_RESULT_BORDER);
    Logger::printMessage(Constants::MSG_RESULT_FILE + data.sourceFile);
    Logger::printMessage(Constants::MSG_RESULT_FORMAT + data.format);
    Logger::printMessage(Constants::MSG_RESULT_RECORDS + std::to_string(data.size()));
    Logger::printMessage(Constants::MSG_RESULT_BORDER);

    if (data.empty())
    {
        Logger::printMessage(Constants::MSG_NO_RECORDS);
        return;
    }

    int recordNumber = 1;
    for (const std::vector<std::pair<std::string, std::string>>& row : data.rows)
    {
        Logger::printMessage(Constants::MSG_RESULT_DIVIDER + std::to_string(recordNumber++) 
        + Constants::MSG_RECORD_SUFFIX);

        for (const std::pair<std::string, std::string>& field : row)
        {
            Logger::printField(field.first, field.second);
        }

        Logger::printNewLine();
    }

    Logger::printMessage(Constants::MSG_RESULT_BORDER);
    Logger::printMessage(Constants::MSG_PARSE_COMPLETE);
    Logger::printMessage(Constants::MSG_RESULT_BORDER);
}
