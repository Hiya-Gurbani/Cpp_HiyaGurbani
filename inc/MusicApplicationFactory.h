#ifndef MUSIC_PLAYER_FACTORY_H
#define MUSIC_PLAYER_FACTORY_H

#include "MusicApplication.h"
#include "MusicLibrary.h"
#include "MiniAudioPlayer.h"
#include "PersistenceManager.h"
#include "PlaylistFactory.h"
#include "PlayerService.h"
#include "Logger.h"
#include "InputHandler.h"
#include "PlaylistController.h"

class MusicApplicationFactory {
public: 
    MusicApplication* create() {
        IMusicLibrary* musicLibrary = new MusicLibrary();
        IAudioPlayer* audioPlayer = new MiniAudioPlayer();
        IPersistenceManager* manager = new PersistenceManager();
        IPlaylistFactory* playlistFactory = new PlaylistFactory();

        IPlayerService* service = new PlayerService(musicLibrary, audioPlayer,
            manager, playlistFactory);

        ILogger* logger = new Logger();
        IInputHandler* inputHandler = new InputHandler(logger);

        IPlaylistController* controller = new PlaylistController(service, logger, inputHandler);

        return new MusicApplication(service, controller, logger, inputHandler);
    }
};

#endif
