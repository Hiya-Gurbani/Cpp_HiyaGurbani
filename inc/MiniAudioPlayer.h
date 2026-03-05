#ifndef MINI_AUDIO_PLAYER_H
#define MINI_AUDIO_PLAYER_H

#include "IAudioPlayer.h"
#include <functional>
#include <string>

class MiniAudioPlayer : public IAudioPlayer {
    struct Impl;
    Impl* impl;
    bool isCurrentlyPlaying;
    std::function<void()> onSongEndCallback;

public:
    MiniAudioPlayer();
    ~MiniAudioPlayer() override;

    MiniAudioPlayer(const MiniAudioPlayer&) = delete;
    MiniAudioPlayer& operator=(const MiniAudioPlayer&) = delete;

    void play(const std::string& filePath) override;
    void pause() override;
    void resume() override;
    void stop() override;
    bool isPlaying() override;

    void setOnSongEnd(std::function<void()> callback) override;
    void checkSongEnd() override;
};

#endif
