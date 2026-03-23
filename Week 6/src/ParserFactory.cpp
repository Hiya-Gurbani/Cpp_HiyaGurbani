#include "ParserFactory.h"
#include "Constants.h"
#include "CsvParser.h"
#include "JsonParser.h"
#include "XmlParser.h"
#include <algorithm>

IParser* ParserFactory::createParser(std::string& filePath) {
    size_t dotPosition = filePath.rfind(Constants::FULL_STOP);
    std::string extension = filePath.substr(dotPosition + 1);
    std::transform(extension.begin(), extension.end(), extension.begin(), ::toupper);

    IParser* parser = nullptr;

    if (extension == Constants::FORMAT_JSON) 
    {
        parser = new JsonParser();
    }
    else if (extension == Constants::FORMAT_CSV)  
    {
        parser = new CsvParser();
    }
    else if (extension == Constants::FORMAT_XML)
    {
        parser = new XmlParser();
    }
    
    return parser;
}
