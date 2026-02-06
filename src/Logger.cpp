#include "Logger.h"
#include <iostream>
#include <string>

const std::string MSG_OPERATIONS_MENU = 
                "\n===============Operations===============\n"
                "1. Matrix Addition\n"
                "2. Matrix Multiplication\n"
                "3. Exit\n"
                "========================================\n";

const std::string Logger::MSG_INPUT_CHOICE = "\nEnter your choice: ";
const std::string Logger::MSG_INPUT_ELEMENT = "Enter element ";
const std::string Logger::MSG_INPUT_ELEMENT = "Enter number of rows: ";

//Input Handler Messages
const std::string Logger::MSG_INVALID_NUMBER = "Invalid Input. Please enter a number: ";
const std::string Logger::MSG_INVALID_INTEGER = "Invalid Input. Please enter an integer: ";
const std::string Logger::MSG_OUT_OF_RANGE = "Invalid Value. Please enter an integer in range: ";

//Menu Handler
const std::string Logger::MSG_PERFORMING_ADDITION = "\nPerforming Matrix Addition: \n";
const std::string Logger::MSG_PERFORMING_MULTIPLY = "\nPerforming Matrix Multiplication: \n";

const std::string Logger::MSG_PROGRAM_EXIT = "Exiting Program...\n";

const std::string Logger::MSG_INPUT_MATRICES_NUMBER = "Enter number of matrices: ";
