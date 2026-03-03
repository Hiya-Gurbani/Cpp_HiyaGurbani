#include "MusicPlayerFactory.h"
#include "MusicPlayer.h"

int main() {
    MusicPlayerFactory factory;
    MusicPlayer* player = factory.create();

    player->handleMainMenu();

    return 0;
}
