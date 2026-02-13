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

    static const int PIN_LENGTH = 4;
    static const int ACCOUNT_NUMBER_LENGTH = 8;
    static const int PHONE_LENGTH = 10;
    static const int MAX_LOGIN_ATTEMPTS = 3;
    static const int MIN_NAME_LENGTH = 3;

    static const int MIN_PASSWORD_LENGTH = 6;

    static const int MIN_TRANSACTION_AMOUNT = 100;
    static const int MAX_TRANSACTION_AMOUNT = 10000;

    inline static const std::string EMPTY_STRING = "";
    inline static const std::string ADMIN_NAME = "Hiya";
    inline static const std::string ADMIN_USERNAME = "hiya";
    inline static const std::string ADMIN_PASSWORD = "system";
    
    
};

#endif
