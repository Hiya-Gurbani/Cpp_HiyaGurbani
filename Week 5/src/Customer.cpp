#include "Customer.h"
#include "Constants.h"
#include "Display.h"
#include "Logger.h"

void Customer::displayInformation() {
    Display::printWithValue(Logger::MSG_DISPLAY_CUSTOMER_NAME, name);
    Display::printWithValue(Logger::MSG_DISPLAY_EMAIL, email);
    Display::printWithValue(Logger::MSG_DISPLAY_PHONE, phone);
    Display::printWithValue(Logger::MSG_DISPLAY_ACCOUNT_NUMBER, account.getAccountNumber());
}

void Customer::displayAccountDetails() {
    Display::printWithValue(Logger::MSG_DISPLAY_ACCOUNT_NUMBER, account.getAccountNumber());
    Display::printWithAmount(Logger::MSG_DISPLAY_BALANCE, account.getBalance());
}
