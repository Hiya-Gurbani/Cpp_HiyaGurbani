#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include "MiniAudioPlayer.h"
#include <iostream>
#include <stdexcept>

struct MiniAudioPlayer::Impl {
    ma_engine engine;
    ma_sound sound;
    bool engineReady;
    bool soundReady;

    Impl() : engineReady(false), soundReady(false) {}
};

MiniAudioPlayer::MiniAudioPlayer()
    : impl(new Impl())
    , isCurrentlyPlaying(false)
{
    if (ma_engine_init(nullptr, &impl->engine) != MA_SUCCESS) {
        delete impl;
        throw std::runtime_error("Failed to initialize audio engine.");
    }
    impl->engineReady = true;
}

MiniAudioPlayer::~MiniAudioPlayer() {
    if (impl != nullptr) 
    {
        if (impl->soundReady) 
        {
            ma_sound_uninit(&impl->sound);
        }
        if (impl->engineReady) 
        {
            ma_engine_uninit(&impl->engine);
        }
        delete impl;
    }
}

void MiniAudioPlayer::play(const std::string& filePath) {
    if (impl->soundReady) 
    {
        ma_sound_stop(&impl->sound);
        ma_sound_uninit(&impl->sound);
        impl->soundReady = false;
    }

    ma_result result = ma_sound_init_from_file(
        &impl->engine,
        filePath.c_str(),
        MA_SOUND_FLAG_ASYNC,
        nullptr,
        nullptr,
        &impl->sound
    );

    if (result != MA_SUCCESS) 
    {
        std::cerr << "Failed to load: " << filePath << "\n";
        isCurrentlyPlaying = false;
    } 
    else 
    {
        impl->soundReady = true;

        if (ma_sound_start(&impl->sound) != MA_SUCCESS) 
        {
            std::cerr << "Failed to start: " << filePath << "\n";
            isCurrentlyPlaying = false;
        } else 
        {
            isCurrentlyPlaying = true;
        }
    }
}

void MiniAudioPlayer::pause() {
    if (impl->soundReady && isCurrentlyPlaying) 
    {
        ma_sound_stop(&impl->sound);
        isCurrentlyPlaying = false;
    }
}

void MiniAudioPlayer::resume() {
    if (impl->soundReady && !isCurrentlyPlaying) 
    {
        ma_sound_start(&impl->sound);
        isCurrentlyPlaying = true;
    }
}

void MiniAudioPlayer::stop() {
    if (impl->soundReady) 
    {
        ma_sound_stop(&impl->sound);
        ma_sound_seek_to_pcm_frame(&impl->sound, 0);
        isCurrentlyPlaying = false;
    }
}

bool MiniAudioPlayer::isPlaying() {
    return isCurrentlyPlaying;
}

void MiniAudioPlayer::setOnSongEnd(std::function<void()> callback) {
    onSongEndCallback = callback;
}

void MiniAudioPlayer::checkSongEnd() {
    if (impl->soundReady && isCurrentlyPlaying) 
    {
        if (!ma_sound_is_playing(&impl->sound)) 
        {
            isCurrentlyPlaying = false;

            if (onSongEndCallback) 
            {
                onSongEndCallback();
            }
        }
    }
}
