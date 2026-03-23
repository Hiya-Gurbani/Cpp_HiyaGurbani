#include "XmlParser.h"
#include "Constants.h"
#include <stdexcept>
#include <map>

std::map<std::string, int> XmlParser::countChildren(const pugi::xml_node& node) {
    std::map<std::string, int> childCount;
    for (pugi::xml_node child = node.first_child(); child; child = child.next_sibling())
    {
        if (child.type() == pugi::node_element)
            childCount[child.name()]++;
    }
    return childCount;
}

void XmlParser::processChildren(const std::string& prefix, const pugi::xml_node& node, std::vector<std::pair<std::string, std::string>>& row) {
    std::map<std::string, int> childCount = countChildren(node);
    std::map<std::string, int> childIndex;

    for (pugi::xml_node child = node.first_child(); child; child = child.next_sibling())
    {
        if (child.type() != pugi::node_element)
        {
            continue;
        }

        std::string childName = child.name();
        std::string key;

        if (childCount[childName] > 1)
        {
            key = prefix.empty()
                ? childName + Constants::OPEN_BRACKET + std::to_string(childIndex[childName]++) + Constants::CLOSE_BRACKET
                : prefix + Constants::FULL_STOP + childName + Constants::OPEN_BRACKET + std::to_string(childIndex[childName]++) + Constants::CLOSE_BRACKET;
        }
        else
        {
            key = prefix.empty() ? childName : prefix + Constants::FULL_STOP + childName;
        }

        pugi::xml_node firstChild = child.first_child();
        bool isTextLeaf = firstChild && firstChild.type() == pugi::node_pcdata && !firstChild.next_sibling();

        if (isTextLeaf)
        {
            row.push_back(std::make_pair(key, std::string(child.child_value())));
        }
        else if (!child.first_child() && !child.first_attribute())
        {
            row.push_back(std::make_pair(key, Constants::EMPTY_STRING));
        }
        else
        {
            flattenNode(key, child, row);
        }
    }
}

void XmlParser::flattenNode(const std::string& prefix, const pugi::xml_node& node, std::vector<std::pair<std::string, std::string>>& row) {
    for (pugi::xml_attribute attribute = node.first_attribute(); attribute; attribute = attribute.next_attribute())
    {
        std::string key = prefix.empty() ? std::string(attribute.name())
                                         : prefix + Constants::FULL_STOP + attribute.name();
        row.push_back(std::make_pair(key, std::string(attribute.value())));
    }

    processChildren(prefix, node, row);
}

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
            std::vector<std::pair<std::string, std::string>> row;
            flattenNode(Constants::EMPTY_STRING, child, row);

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


Constants::ParsedData XmlParser::parse(const std::string& filePath) {
    pugi::xml_document document;
    pugi::xml_parse_result parseResult = document.load_file(filePath.c_str());

    if (!parseResult) 
    {
        throw std::runtime_error(Constants::MSG_XML_PARSE_FAIL + std::string(parseResult.description()));
    }

    return convert(document, filePath);
}
