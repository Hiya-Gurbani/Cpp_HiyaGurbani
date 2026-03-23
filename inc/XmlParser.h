#ifndef XML_PARSER_H
#define XML_PARSER_H

#include "IParser.h"
#include "Constants.h"
#include <pugixml.hpp>
#include <map>

class XmlParser : public IParser {
    std::map<std::string, int> countChildren(const pugi::xml_node& node);
    void processChildren(const std::string& prefix, const pugi::xml_node& node, std::vector<std::pair<std::string, std::string>>& row);
    void flattenNode(const std::string& prefix, const pugi::xml_node& node, std::vector<std::pair<std::string, std::string>>& row);
    Constants::ParsedData convert(const pugi::xml_document& document, const std::string& filePath);

public:
    Constants::ParsedData parse(const std::string& filePath) override;

    std::string getFormat() override {
        return Constants::FORMAT_XML;
    }
};

#endif
