#include "Validator.h"
#include "Constants.h"
#include "Logger.h"
#include <algorithm>
#include <fstream>

bool Validator::isValidChoice(std::string& choice) {
    bool isValid = false;

    if (choice.length() != 1)
    {
        Logger::printMessage(Constants::MSG_INVALID_CHOICE);
    }
    else if (choice[0] != Constants::CHOICE_YES && choice[0] != Constants::CHOICE_YES_UPPER &&
        choice[0] != Constants::CHOICE_NO && choice[0] != Constants::CHOICE_NO_UPPER)
    {
        Logger::printMessage(Constants::MSG_INVALID_CHOICE);
    }
    else
    {
        isValid = true;
    }

    return isValid;
}

bool Validator::isSupportedExtension(std::string& path) {
    bool isValidExtension = false;

    size_t dotPosition = path.rfind(Constants::FULL_STOP);
    if (dotPosition != std::string::npos)
    {
        std::string extension = path.substr(dotPosition + 1);
        std::transform(extension.begin(), extension.end(), extension.begin(), ::toupper);
        isValidExtension = (extension == Constants::FORMAT_JSON 
        || extension == Constants::FORMAT_CSV || extension == Constants::FORMAT_XML);
    }

    return isValidExtension;
}

bool Validator::isValidFilePath(std::string& path) {
    bool isValid = false;

    if (path.empty()) 
    {
        Logger::printMessage(Constants::MSG_EMPTY_PATH);
    }
    else if (!isSupportedExtension(path))
    {
        Logger::printMessage(Constants::MSG_UNSUPPORTED_TYPE);
    }
    else if (!std::ifstream(path).is_open()) 
    {
        Logger::printMessage(Constants::MSG_FILE_NOT_FOUND + path);
        Logger::printMessage(Constants::MSG_CHECK_PATH);
    }
    else
    {
        isValid = true;
    }

    return isValid;
}
