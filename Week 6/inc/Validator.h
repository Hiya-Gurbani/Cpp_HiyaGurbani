#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

class Validator {
    static bool isSupportedExtension(std::string& path);
    
public:
    static bool isValidChoice(std::string& choice);
    static bool isValidFilePath(std::string& path);    
};

#endif
