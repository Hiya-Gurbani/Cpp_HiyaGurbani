#include "Validator.h"
#include "Constants.h"
#include "Logger.h"
#include <algorithm>
#include <fstream>

bool Validator::fileExists(std::string& path) {
    std::ifstream file(path);
    return file.is_open();
}

bool Validator::isSupportedExtension(std::string& path) {
    bool isValidExtension = false;

    size_t dotPosition = path.rfind('.');
    if (dotPosition != std::string::npos)
    {
        std::string extension = path.substr(dotPosition + 1);
        std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
        isValidExtension = 
        (extension == "json" || extension == "csv" || extension == "xml");
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
    else if (!fileExists(path)) 
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
