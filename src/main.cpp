#include <iostream>
#include <SDL2/SDL.h>

#include "core/audio/AudioPlayer.h"

int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_AUDIO);

    AudioProperties propList;
    propList.frequency = 48000;
    propList.n_channels = 1;
    propList.samples = 4096;

    AudioPlayer *audio_player = new AudioPlayer(propList);
    audio_player->play();

    std::cin.get();

    audio_player->pause();
    delete audio_player;

    SDL_Quit();

    return 0;
}