#include "JsonParser.h"
#include "Constants.h"
#include <fstream>
#include <stdexcept>

void JsonParser::processArray(const nlohmann::json& jsonObject, Constants::ParsedData& result) {
    for (const auto& element : jsonObject)
    {
        std::map<std::string, std::string> row;
        for (const auto& [key, value] : element.items())
        {
            row[key] = value.is_string() ? value.get<std::string>() : value.dump();
        }
        result.rows.push_back(row);
    }
}

Constants::ParsedData JsonParser::convert(const nlohmann::json& jsonObject, const std::string& filePath) {
    Constants::ParsedData result;
    result.sourceFile = filePath;
    result.format     = getFormat();

    try
    {
        if (!jsonObject.is_array())
        {
            throw std::runtime_error(Constants::MSG_JSON_BAD_STRUCT);
        }

        processArray(jsonObject, result);
    }
    catch (const nlohmann::json::type_error& error)
    {
        throw std::runtime_error(Constants::MSG_JSON_TYPE_ERROR + std::string(error.what()));
    }
    catch (const nlohmann::json::out_of_range& error)
    {
        throw std::runtime_error(Constants::MSG_JSON_KEY_ERROR + std::string(error.what()));
    }

    return result;
}

Constants::ParsedData JsonParser::parse(std::string& filePath) {
    std::ifstream file(filePath);

    nlohmann::json jsonObject;
    try 
    {
        file >> jsonObject;
    }
    catch (const nlohmann::json::parse_error& error) 
    {
        throw std::runtime_error(Constants::MSG_JSON_SYNTAX_ERROR + std::string(error.what()));
    }

    return convert(jsonObject, filePath);
}
