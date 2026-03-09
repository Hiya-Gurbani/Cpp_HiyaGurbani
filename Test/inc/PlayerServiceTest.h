#ifndef PLAYER_SERVICE_TEST_H
#define PLAYER_SERVICE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "PlayerService.h"
#include "IMockMusicLibrary.h"
#include "IMockAudioPlayer.h"
#include "IMockPersistenceManager.h"
#include "IMockPlaylistFactory.h"
#include "IMockPlaylist.h"

class GivenPlayerServiceTest : public ::testing::Test {
protected:
    testing::NiceMock<IMockMusicLibrary>* mockMusicLibrary;
    testing::NiceMock<IMockAudioPlayer>* mockAudioPlayer;
    testing::NiceMock<IMockPersistenceManager>* mockPersistenceManager;
    testing::NiceMock<IMockPlaylistFactory>* mockPlaylistFactory;
    PlayerService* playerService;

    void SetUp() override {
        mockMusicLibrary = new testing::NiceMock<IMockMusicLibrary>();
        mockAudioPlayer = new testing::NiceMock<IMockAudioPlayer>();
        mockPersistenceManager = new testing::NiceMock<IMockPersistenceManager>();
        mockPlaylistFactory = new testing::NiceMock<IMockPlaylistFactory>();

        playerService = new PlayerService(
            mockMusicLibrary,
            mockAudioPlayer,
            mockPersistenceManager,
            mockPlaylistFactory
        );
    }

    void TearDown() override {
        delete playerService;
    }
};

#endif
