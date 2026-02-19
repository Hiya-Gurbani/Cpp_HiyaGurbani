#include "Utility.h"
#include "Logger.h"
#include "Validator.h"
#include <iostream>
#include <iomanip>

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

    int recordNum = 1;
    for (const auto& row : data.rows)
    {
        Logger::printMessage(Constants::MSG_RESULT_DIVIDER + std::to_string(recordNum++) + " ---");
        for (const auto& [key, value] : row)
        {
            std::cout << "  " << std::left << std::setw(15) << key << " : " << value << "\n";
        }
        std::cout << "\n";
    }

    Logger::printMessage(Constants::MSG_RESULT_BORDER);
    Logger::printMessage(Constants::MSG_PARSE_COMPLETE);
    Logger::printMessage(Constants::MSG_RESULT_BORDER);
}
