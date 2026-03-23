#ifndef IPARSER_H
#define IPARSER_H

#include "Constants.h"
#include <string>

class IParser {
public:
    virtual Constants::ParsedData parse(const std::string& filename) = 0;
    virtual std::string getFormat() = 0;
    virtual ~IParser() {}
};

#endif
