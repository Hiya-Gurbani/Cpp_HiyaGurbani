#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "IParser.h"
#include "Constants.h"
#include "nlohmann/json.hpp"

class JsonParser : public IParser {
    void flattenJson(const std::string& prefix, const nlohmann::ordered_json& jsonObject, std::vector<std::pair<std::string, std::string>>& row);
    void processArray(const nlohmann::ordered_json& jsonObject, Constants::ParsedData& result);
    Constants::ParsedData convert(const nlohmann::ordered_json& jsonObject, const std::string& filePath);

public:
    Constants::ParsedData parse(const std::string& filePath) override;

    std::string getFormat() override {
        return Constants::FORMAT_JSON;
    }
};

#endif 
