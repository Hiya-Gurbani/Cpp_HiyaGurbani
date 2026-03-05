#include "SongTest.h"

// Operator<

TEST_F(GivenSongTest, WhenFirstSongNameIsSmaller_ThenFirstSongIsLessThanSecond) {
    bool result = songOne < songTwo;
    EXPECT_TRUE(result);
}

TEST_F(GivenSongTest, WhenFirstSongNameIsLarger_ThenFirstSongIsNotLessThanSecond) {
    bool result = songTwo < songOne;
    EXPECT_FALSE(result);
}

TEST_F(GivenSongTest, WhenTwoSongsHaveSameName_ThenNeitherIsLessThanOther) {
    bool firstLessThanThird = songOne < songThree;
    bool thirdLessThanFirst = songThree < songOne;
    EXPECT_FALSE(firstLessThanThird);
    EXPECT_FALSE(thirdLessThanFirst);
}

TEST_F(GivenSongTest, WhenSongComparedWithItself_ThenNotLessThanItself) {
    bool result = songOne < songOne;
    EXPECT_FALSE(result);
}
