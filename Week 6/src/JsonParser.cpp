#include "JsonParser.h"
#include "Constants.h"
#include <fstream>
#include <stdexcept>

void JsonParser::flattenJson(const std::string& prefix, const nlohmann::ordered_json& jsonObject, std::vector<std::pair<std::string, std::string>>& row) {
    if (jsonObject.is_object())
    {
        for (nlohmann::ordered_json::const_iterator field = jsonObject.begin(); field != jsonObject.end(); field++)
        {
            std::string key = prefix.empty() ? field.key() : prefix + Constants::FULL_STOP + field.key();
            flattenJson(key, field.value(), row);
        }
    }
    else if (jsonObject.is_array())
    {
        for (size_t index = 0; index < jsonObject.size(); index++)
        {
            std::string key = prefix + Constants::OPEN_BRACKET + std::to_string(index) + Constants::CLOSE_BRACKET;
            flattenJson(key, jsonObject[index], row);
        }
    }
    else if (jsonObject.is_null())
    {
        row.push_back(std::make_pair(prefix, Constants::MSG_NULL));
    }
    else if (jsonObject.is_string())
    {
        row.push_back(std::make_pair(prefix, jsonObject.get<std::string>()));
    }
    else
    {
        row.push_back(std::make_pair(prefix, jsonObject.dump()));
    }
}

void JsonParser::processArray(const nlohmann::ordered_json& jsonObject, Constants::ParsedData& result) {
    for (const nlohmann::ordered_json& element : jsonObject)
    {
        std::vector<std::pair<std::string, std::string>> row;
        flattenJson(Constants::EMPTY_STRING, element, row);
        result.rows.push_back(row);
    }
}

Constants::ParsedData JsonParser::convert(const nlohmann::ordered_json& jsonObject, const std::string& filePath) {
    Constants::ParsedData result;
    result.sourceFile = filePath;
    result.format = getFormat();

    try
    {
        if (jsonObject.is_array())
        {
            processArray(jsonObject, result);
        }
        else if (jsonObject.is_object())
        {
            std::vector<std::pair<std::string, std::string>> row;
            flattenJson(Constants::EMPTY_STRING, jsonObject, row);
            result.rows.push_back(row);
        }
        else
        {
            throw std::runtime_error(Constants::MSG_JSON_BAD_STRUCT);
        }
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
