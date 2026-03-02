
// Compile:
//   g++ player.cpp -o player.out -lpthread -ldl -lm
// Run:
//   ./player.out music/Aahatein.mp3

#define MINIAUDIO_IMPLEMENTATION
#include "vendor/miniaudio.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./test_audio <path_to_mp3>\n";
        std::cout << "Example: ./test_audio music/song.mp3\n";
        return 1;
    }

    std::string filePath = argv[1];
    std::cout << "Initializing audio engine...\n";

    // Step 1: Init engine
    ma_engine engine;
    ma_result result = ma_engine_init(nullptr, &engine);
    if (result != MA_SUCCESS) {
        std::cerr << "FAILED to init audio engine. Code: " << result << "\n";
        std::cerr << "Check your audio device is available.\n";
        return 1;
    }
    std::cout << "✓ Engine initialized\n";

    // Step 2: Load and play sound
    ma_sound sound;
    result = ma_sound_init_from_file(
        &engine,
        filePath.c_str(),
        MA_SOUND_FLAG_ASYNC,
        nullptr,
        nullptr,
        &sound
    );
    if (result != MA_SUCCESS) {
        std::cerr << "FAILED to load file: " << filePath << "\n";
        std::cerr << "Code: " << result << "\n";
        std::cerr << "Check the file exists and is a valid .mp3\n";
        ma_engine_uninit(&engine);
        return 1;
    }
    std::cout << "✓ File loaded: " << filePath << "\n";

    result = ma_sound_start(&sound);
    if (result != MA_SUCCESS) {
        std::cerr << "FAILED to start playback. Code: " << result << "\n";
        ma_sound_uninit(&sound);
        ma_engine_uninit(&engine);
        return 1;
    }
    std::cout << "✓ Playing...\n";

    // Step 3: Test pause/resume
    std::cout << "\n[20s] Playing...\n";
    std::this_thread::sleep_for(std::chrono::seconds(20));

    std::cout << "[2s] Pausing...\n";
    ma_sound_stop(&sound);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "[2s] Resuming...\n";
    ma_sound_start(&sound);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "[done] Stopping.\n";

    // Step 4: Cleanup 
    ma_sound_uninit(&sound);
    ma_engine_uninit(&engine);

    std::cout << "✓ All good! miniaudio is working.\n";
    return 0;
}
