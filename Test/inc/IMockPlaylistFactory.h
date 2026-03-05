#ifndef MOCK_PLAYLIST_FACTORY_H
#define MOCK_PLAYLIST_FACTORY_H

#include <gmock/gmock.h>
#include "IPlaylistFactory.h"

class IMockPlaylistFactory : public IPlaylistFactory {
public:
    MOCK_METHOD(IPlaylist*, create, (const std::string& playlistName), (override));
};

#endif
