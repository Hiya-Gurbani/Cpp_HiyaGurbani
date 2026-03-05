#ifndef SONG_TEST_H
#define SONG_TEST_H

#include <gtest/gtest.h>
#include "Song.h"

class GivenSongTest : public ::testing::Test {
protected:
    Song songOne;
    Song songTwo;
    Song songThree;

    void SetUp() override {
        songOne = Song("Aahatein", "Songs/Aahatein.mp3");
        songTwo = Song("Believer", "Songs/Believer.mp3");
        songThree = Song("Aahatein", "Songs/Aahatein.mp3");
    }
};

#endif
