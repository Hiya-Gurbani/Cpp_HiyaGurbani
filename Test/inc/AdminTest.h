#ifndef ADMIN_TEST_H
#define ADMIN_TEST_H

#include "Admin.h"
#include <gtest/gtest.h>

class AdminTest : public ::testing::Test {
protected:
    Admin admin;
};

#endif
