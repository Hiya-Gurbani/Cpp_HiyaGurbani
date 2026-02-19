#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "IParser.h"
#include "Constants.h"
#include "json.hpp"

class JsonParser : public IParser {
    Constants::ParsedData convert(const nlohmann::json& jsonObject, const std::string& filePath);

public:
    Constants::ParsedData parse(std::string& filePath) override;
    std::string getFormat() override;
};

#endif 
