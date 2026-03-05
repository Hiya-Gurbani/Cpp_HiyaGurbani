#ifndef MUSIC_LIBRARY_TEST_H
#define MUSIC_LIBRARY_TEST_H

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>
#include "MusicLibrary.h"

class GivenMusicLibraryTest : public ::testing::Test {
protected:
    MusicLibrary* musicLibrary;

    void SetUp() override {
        std::filesystem::create_directory("TestSongs");
        std::ofstream("TestSongs/Aahatein.mp3").close();
        std::ofstream("TestSongs/Believer.mp3").close();
        std::ofstream("TestSongs/Tum Hi Ho.mp3").close();
        musicLibrary = new MusicLibrary("TestSongs");
    }

    void TearDown() override {
        std::filesystem::remove_all("TestSongs");
        delete musicLibrary;
    }
};

class GivenEmptyMusicLibraryTest : public ::testing::Test {
protected:
    MusicLibrary* musicLibrary;

    void SetUp() override {
        std::filesystem::create_directory("TestSongsEmpty");
        musicLibrary = new MusicLibrary("TestSongsEmpty");
    }

    void TearDown() override {
        std::filesystem::remove_all("TestSongsEmpty");
        delete musicLibrary;
    }
};

class GivenInvalidFolderMusicLibraryTest : public ::testing::Test {
protected:
    MusicLibrary* musicLibrary;

    void SetUp() override {
        musicLibrary = new MusicLibrary("NonExistentFolder");
    }

    void TearDown() override {
        delete musicLibrary;
    }
};

#endif
