#include "Utility.h"
#include "Logger.h"
#include "Validator.h"
#include <iostream>

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