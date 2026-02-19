#ifndef XML_PARSER_H
#define XML_PARSER_H

#include "IParser.h"
#include "Constants.h"
#include <pugixml.hpp>

class XmlParser : public IParser {
    Constants::ParsedData convert(const pugi::xml_document& document, const std::string& filePath);

public:
    Constants::ParsedData parse(std::string& filePath) override;
    std::string getFormat() override;
};

#endif
