#ifndef MOCK_PERSISTENCE_MANAGER_H
#define MOCK_PERSISTENCE_MANAGER_H

#include <gmock/gmock.h>
#include "IPersistenceManager.h"

class IMockPersistenceManager : public IPersistenceManager {
public:
    MOCK_METHOD(void, save, (std::map<std::string, IPlaylist*>& playlists), (override));
    MOCK_METHOD(void, load, (std::map<std::string, IPlaylist*>& playlists, IPlaylistFactory* playlistFactory), (override));
};

#endif
