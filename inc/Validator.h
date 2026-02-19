#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

class Validator {
    static bool fileExists(std::string& path);
    static bool isSupportedExtension(std::string& path);
    
public:
    static bool isValidFilePath(std::string& path);    
};

#endif
