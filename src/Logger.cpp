#include "Logger.h"
#include "Constants.h"
#include <iostream>

void Logger::printMessage(const std::string& message) {
    std::cout << message;
}

void Logger::printResults(Constants::ParsedData& data) {
    std::cout << "\n========================================\n";
    std::cout << "  File   : " << data.sourceFile << "\n";
    std::cout << "  Format : " << data.format << "\n";
    std::cout << "  Records: " << data.size() << "\n";
    std::cout << "========================================\n\n";

    if (data.empty()) 
    {
        std::cout << "  No records found.\n";
        return;
    }

    int recordNum = 1;
    for (const auto& row : data.rows) 
    {
        std::cout << "--- Record " << recordNum++ << " ---\n";
        for (const auto& [key, value] : row) 
        {
            std::cout << "  " << key << " : " << value << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "========================================\n";
    std::cout << "  Parsing complete.\n";
    std::cout << "========================================\n";
}
