#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "IParser.h"
#include "Constants.h"
#include "nlohmann/json.hpp"

class JsonParser : public IParser {
    void processArray(const nlohmann::json& jsonObject, Constants::ParsedData& result);
    Constants::ParsedData convert(const nlohmann::json& jsonObject, const std::string& filePath);

public:
    Constants::ParsedData parse(std::string& filePath) override;

    std::string getFormat() override {
        return Constants::FORMAT_JSON;
    }
};

#endif 
