#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

class Constants {
public:
    enum UserRole {
        ADMIN,
        CUSTOMER
    };

    enum TransactionType {
        DEPOSIT,
        WITHDRAWAL
    };

    enum InputType {
        NAME,
        EMAIL,
        PHONE,
        ACCOUNT_NUMBER,
        PIN,
        USERNAME,
        PASSWORD
    };

    static const long INITIAL_TRANSACTION_ID = 1;
    static const long INITIAL_ACCOUNT_NUMBER = 10000000;

    static const int PIN_LENGTH = 4;
    static const int MIN_PIN_VALUE = 1000;
    static const int MAX_PIN_VALUE = 9999;

    static const int ACCOUNT_NUMBER_LENGTH = 8;
    static const int PHONE_LENGTH = 10;
    static const int MAX_LOGIN_ATTEMPTS = 3;
    static const int MIN_NAME_LENGTH = 3;
    static const int MIN_PASSWORD_LENGTH = 6;
    static const int MINI_STATEMENT_MAX_TRANSACTIONS = 5;

    static const int MIN_TRANSACTION_AMOUNT = 100;
    static const int MAX_TRANSACTION_AMOUNT = 10000;

    static const int ID_WIDTH = 5;
    static const int TYPE_WIDTH = 12;
    static const int AMOUNT_WIDTH = 10;
    static const int POSTBALANCE_WIDTH = 15;
    static const int DECIMAL_PRECISION = 2;

    static const char NEW_LINE = '\n';
    static const char AT_THE_RATE = '@';
    static const char FULL_STOP = '.';
    static const char WHITESPACE = ' ';
    static const char HYPHEN = '-';
    static const char TAB = '\t';

    inline static const std::string EMPTY_STRING = "";
    inline static const std::string ADMIN_NAME = "Hiya";
    inline static const std::string ADMIN_USERNAME = "hiya";
    inline static const std::string ADMIN_PASSWORD = "system"; 
    inline static const std::string WHITESPACE_CHARS = " \t\n\r";
};

#endif
