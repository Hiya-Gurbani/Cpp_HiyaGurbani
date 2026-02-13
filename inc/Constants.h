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

    // static const int ACCOUNT_NUMBER_LENGTH = 8;
    static const int PIN_LENGTH = 4;
    static const int MAX_LOGIN_ATTEMPTS = 3;
    inline static const std::string ADMIN_NAME = "Hiya";
    inline static const std::string ADMIN_USERNAME = "hiya";
    inline static const std::string ADMIN_PASSWORD = "system";
    
    
};

#endif
