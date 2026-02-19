#include "CsvParser.h"
#include "Constants.h"
#include <stdexcept>

Constants::ParsedData CsvParser::convert(rapidcsv::Document& document, const std::string& filePath) {
    Constants::ParsedData result;
    result.sourceFile = filePath;
    result.format = getFormat();

    try 
    {
        std::vector<std::string> headers = document.GetColumnNames();

        if (headers.empty())
        {
            throw std::runtime_error(Constants::MSG_CSV_NO_HEADERS);
        }
        
        size_t rowCount = document.GetRowCount();

        for (size_t rowIndex = 0; rowIndex < rowCount; rowIndex++) 
        {
            std::map<std::string, std::string> row;
            for (const auto& header : headers) 
            {
                row[header] = document.GetCell<std::string>(header, rowIndex);
            }
            result.rows.push_back(row);
        }
    }
    catch (const std::out_of_range& error) 
    {
        throw std::runtime_error(Constants::MSG_CSV_OUT_OF_RANGE + std::string(error.what()));
    }

    return result;
}

std::string CsvParser::getFormat() {
    return "CSV";
}

Constants::ParsedData CsvParser::parse(std::string& filePath) {
    rapidcsv::Document document;

    try 
    {
        document = rapidcsv::Document(filePath);
    }
    catch (const std::exception& error) 
    {
        throw std::runtime_error(Constants::MSG_CSV_READ_FAIL + std::string(error.what()));
    }

    return convert(document, filePath);
}
