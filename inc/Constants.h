#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <vector>
#include <utility>

namespace Constants {

    struct ParsedData {
        std::string sourceFile;
        std::string format;
        std::vector<std::vector<std::pair<std::string, std::string>>> rows;

        size_t size() { 
            return rows.size(); 
        }

        bool empty() { 
            return rows.empty(); 
        }
    };

    //Constants
    inline constexpr char FULL_STOP = '.';
    inline constexpr char CHOICE_YES = 'y';
    inline constexpr char CHOICE_YES_UPPER = 'Y';
    inline constexpr char CHOICE_NO = 'n';
    inline constexpr char CHOICE_NO_UPPER = 'N';

    // Format Messages
    inline const std::string FORMAT_JSON = "JSON";
    inline const std::string FORMAT_CSV = "CSV";
    inline const std::string FORMAT_XML = "XML";

    // Welcome Message
    inline const std::string MSG_WELCOME = 
    "\n========================================\n"
    "       Welcome to File Parser App       \n"
    "========================================\n"
    "This app can parse the following formats:\n"
    "  1. JSON (.json)\n"
    "  2. CSV  (.csv)\n"
    "  3. XML  (.xml)\n"
    "\n----------------------------------------\n\n";

    // Input Messages
    inline const std::string MSG_ENTER_FILE_PATH = "Enter the full file path: ";
    inline const std::string MSG_CONTINUE = "\nParse another file? (y/n): ";
    inline const std::string MSG_INVALID_CHOICE = "\nInvalid input. Please enter y or n: ";
    
    inline const std::string MSG_EXITING_PROGRAM = "\nThank you for using the parser!\n";

    // Validation Messages
    inline const std::string MSG_EMPTY_PATH = "File path cannot be empty. Try again.\n\n";
    inline const std::string MSG_NO_EXTENSION = "No file extension found. Please provide a file with extension.\n\n";
    inline const std::string MSG_UNSUPPORTED_TYPE  = "Unsupported file type. Supported: .json, .csv, .xml\n\n";
    inline const std::string MSG_FILE_NOT_FOUND = "File not found: ";
    inline const std::string MSG_CHECK_PATH = " Please check the path and try again.\n\n";

    // Result Messages
    inline const std::string MSG_RESULT_BORDER = "\n========================================\n";
    inline const std::string MSG_RESULT_FILE = "  File   : ";
    inline const std::string MSG_RESULT_FORMAT = "\n  Format : ";
    inline const std::string MSG_RESULT_RECORDS = "\n  Records: ";
    inline const std::string MSG_RESULT_DIVIDER = "\n--- Record ";
    inline const std::string MSG_RECORD_SUFFIX = " ---\n";
    inline const std::string MSG_NO_RECORDS = "  No records found.\n";
    inline const std::string MSG_PARSE_COMPLETE = "  Parsing complete.";

    // Error Messages
    inline const std::string MSG_ERROR_PREFIX = "[Error] ";

    // Parser Error Messages
    inline const std::string MSG_JSON_OPEN_FAIL = "[JsonParser] Could not open file: ";
    inline const std::string MSG_JSON_SYNTAX_ERROR = "[JsonParser] Invalid JSON syntax: ";
    inline const std::string MSG_JSON_TYPE_ERROR = "[JsonParser] Type mismatch: ";
    inline const std::string MSG_JSON_KEY_ERROR = "[JsonParser] Key not found: ";
    inline const std::string MSG_JSON_BAD_STRUCT = "[JsonParser] Unsupported JSON structure. Expected object or array.";

    inline const std::string MSG_CSV_READ_FAIL = "[CsvParser] Could not read CSV file: ";
    inline const std::string MSG_CSV_NO_HEADERS = "[CsvParser] CSV file has no headers.";
    inline const std::string MSG_CSV_OUT_OF_RANGE  = "[CsvParser] Out of range while reading CSV: ";

    inline const std::string MSG_XML_PARSE_FAIL = "[XmlParser] Could not parse XML file: ";
    inline const std::string MSG_XML_NO_ROOT = "[XmlParser] XML file has no root element.";
    inline const std::string MSG_XML_READ_ERROR = "[XmlParser] Error while reading XML: ";
}

#endif
