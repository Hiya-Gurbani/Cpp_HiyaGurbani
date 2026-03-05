#ifndef PLAYLIST_TEST_H
#define PLAYLIST_TEST_H

#include <gtest/gtest.h>
#include "Playlist.h"

class GivenPlaylistTest : public ::testing::Test {
protected:
    Playlist playlist;
    Song songOne;
    Song songTwo;
    Song songThree;

    void SetUp() override {
        playlist = Playlist("Test Playlist");
        songOne = Song("Aahatein", "Songs/Aahatein.mp3");
        songTwo = Song("Believer", "Songs/Believer.mp3");
        songThree = Song("Tum Hi Ho", "Songs/TumHiHo.mp3");
    }
};

#endif