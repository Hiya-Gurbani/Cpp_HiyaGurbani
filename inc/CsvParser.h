#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include "IParser.h"
#include "Constants.h"
#include <rapidcsv.h>

class CsvParser : public IParser {
    Constants::ParsedData convert(rapidcsv::Document& doc, const std::string& filePath);

public:
    Constants::ParsedData parse(std::string& filePath) override;
    
    std::string getFormat() override {
        return Constants::FORMAT_CSV;
    }
};

#endif
