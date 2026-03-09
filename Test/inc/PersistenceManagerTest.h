#ifndef PERSISTENCE_MANAGER_TEST_H
#define PERSISTENCE_MANAGER_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include <filesystem>
#include "PersistenceManager.h"
#include "IMockLogger.h"
#include "IMockPlaylist.h"
#include "IMockPlaylistFactory.h"

class GivenPersistenceManagerTest : public ::testing::Test {
protected:
    IMockLogger mockLogger;
    PersistenceManager* persistenceManager;
    std::string testFilePath;

    void SetUp() override {
        testFilePath = "testPlaylists.txt";
        persistenceManager = new PersistenceManager(&mockLogger, testFilePath);

        ON_CALL(mockLogger, printMessage(testing::_))
        .WillByDefault(testing::Return());
    }

    void TearDown() override {
        std::filesystem::remove(testFilePath);
        delete persistenceManager;
    }
};

#endif
