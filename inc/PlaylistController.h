#ifndef PLAYLIST_CONTROLLER_H
#define PLAYLIST_CONTROLLER_H

#include "IPlaylistController.h"
#include "IPlayerService.h"
#include "ILogger.h"
#include "IInputHandler.h"

class PlaylistController : public IPlaylistController {
    IPlayerService* playerService;
    ILogger* logger;
    IInputHandler* inputHandler;

    void handlePlayPause();
    void displayLibrarySongs();
    void handleAddSong();
    void handleRemoveSong();
    void handleMoveSongUpward();
    void handleMoveSongDownward();
    bool handlePlaylistChoice(int choice);
    void displayPlaylistSongs();
    void handlePlaylistDetail();
    
    void handleOpenPlaylist();
    void handleCreatePlaylist();
    void handleDeletePlaylist();

    void displayAllPlaylists();

public:
    PlaylistController(IPlayerService* playerService,
                       ILogger* logger,
                       IInputHandler* inputHandler);

    void handlePlaylistMenu() override;
};

#endif