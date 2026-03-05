#ifndef PLAYER_SERVICE_TEST_H
#define PLAYER_SERVICE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "PlayerService.h"
#include "MockMusicLibrary.h"
#include "MockAudioPlayer.h"
#include "MockPersistenceManager.h"
#include "MockPlaylistFactory.h"
#include "MockPlaylist.h"

class GivenPlayerServiceTest : public ::testing::Test {
protected:
    MockMusicLibrary mockMusicLibrary;
    MockAudioPlayer mockAudioPlayer;
    MockPersistenceManager mockPersistenceManager;
    MockPlaylistFactory mockPlaylistFactory;
    PlayerService* playerService;

    void SetUp() override {
        EXPECT_CALL(mockAudioPlayer, setOnSongEnd(testing::_));
        playerService = new PlayerService(
            &mockMusicLibrary,
            &mockAudioPlayer,
            &mockPersistenceManager,
            &mockPlaylistFactory
        );
    }

    void TearDown() override {
        delete playerService;
    }
};

#endif
