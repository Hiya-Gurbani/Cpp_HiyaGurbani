#ifndef PARSER_FACTORY_H
#define PARSER_FACTORY_H

#include "IParser.h"
#include <memory>
#include <string>

class ParserFactory {
public:
    static IParser* createParser(std::string& filePath);
};

#endif
