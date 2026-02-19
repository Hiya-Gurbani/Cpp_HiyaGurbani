#include "ParserFactory.h"
#include "JsonParser.h"
#include "CsvParser.h"
#include "XmlParser.h"
#include <algorithm>

IParser* ParserFactory::createParser(std::string& filePath) {
    size_t dotPosition = filePath.rfind('.');
    std::string extension = filePath.substr(dotPosition + 1);
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

    IParser* parser = nullptr;

    if (extension == "json") 
    {
        parser = new JsonParser();
    }
    else if (extension == "csv")  
    {
        parser = new CsvParser();
    }
    else if (extension == "xml")
    {
        parser = new XmlParser();
    }
    
    return parser;
}
