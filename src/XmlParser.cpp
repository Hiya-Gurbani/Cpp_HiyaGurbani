#include "XmlParser.h"
#include "Constants.h"
#include <stdexcept>

Constants::ParsedData XmlParser::convert(const pugi::xml_document& document, const std::string& filePath) {
    Constants::ParsedData result;
    result.sourceFile = filePath;
    result.format = getFormat();

    try 
    {
        pugi::xml_node root = document.document_element();

        if (root.empty())
        {
            throw std::runtime_error(Constants::MSG_XML_NO_ROOT);
        }
            
        for (pugi::xml_node child = root.first_child(); child; child = child.next_sibling())
        {
            std::map<std::string, std::string> row;

            for (pugi::xml_attribute attribute = child.first_attribute(); attribute; attribute = attribute.next_attribute())
            {
                row[attribute.name()] = attribute.value();
            }

            for (pugi::xml_node subchild = child.first_child(); subchild; subchild = subchild.next_sibling()) 
            {
                row[subchild.name()] = subchild.child_value();
            }

            if (!row.empty())
            {
                result.rows.push_back(row);
            }
        }
    }
    catch (const std::exception& error) 
    {
        throw std::runtime_error(Constants::MSG_XML_READ_ERROR + std::string(error.what()));
    }

    return result;
}

Constants::ParsedData XmlParser::parse(std::string& filePath) {
    pugi::xml_document document;
    pugi::xml_parse_result parseResult = document.load_file(filePath.c_str());

    if (!parseResult) 
    {
        throw std::runtime_error(Constants::MSG_XML_PARSE_FAIL + std::string(parseResult.description()));
    }

    return convert(document, filePath);
}
