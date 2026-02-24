#include "JsonParser.h"
#include "Constants.h"
#include <fstream>
#include <stdexcept>

void JsonParser::processArray(const nlohmann::ordered_json& jsonObject, Constants::ParsedData& result) {
    for (const nlohmann::ordered_json& element : jsonObject)
    {
        std::vector<std::pair<std::string, std::string>> row;
        for (nlohmann::ordered_json::const_iterator field = element.begin(); field != element.end(); field++)
        {
            std::string value = field.value().is_string() ? field.value().get<std::string>() : field.value().dump();
            row.push_back(std::make_pair(field.key(), value));
        }
        
        result.rows.push_back(row);
    }
}

Constants::ParsedData JsonParser::convert(const nlohmann::ordered_json& jsonObject, const std::string& filePath) {
    Constants::ParsedData result;
    result.sourceFile = filePath;
    result.format = getFormat();

    try
    {
        if (!jsonObject.is_array())
        {
            throw std::runtime_error(Constants::MSG_JSON_BAD_STRUCT);
        }

        processArray(jsonObject, result);
    }
    catch (const nlohmann::ordered_json::type_error& error)
    {
        throw std::runtime_error(Constants::MSG_JSON_TYPE_ERROR + std::string(error.what()));
    }
    catch (const nlohmann::ordered_json::out_of_range& error)
    {
        throw std::runtime_error(Constants::MSG_JSON_KEY_ERROR + std::string(error.what()));
    }

    return result;
}

Constants::ParsedData JsonParser::parse(const std::string& filePath) {
    std::ifstream file(filePath);

    nlohmann::ordered_json jsonObject;
    try 
    {
        file >> jsonObject;
    }
    catch (const nlohmann::ordered_json::parse_error& error) 
    {
        throw std::runtime_error(Constants::MSG_JSON_SYNTAX_ERROR + std::string(error.what()));
    }

    return convert(jsonObject, filePath);
}
