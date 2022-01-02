#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <math.h>

#include <iostream>

#include "sound-generators/SoundGenerator.h"
#include "AudioProperties.h"

#define PI 3.14159265

class AudioPlayer {
public:
    AudioPlayer(AudioProperties properties);

    void play();
    void pause();

    void updateData(void *sound_generators, Uint8 *byteStream, int byteStreamLength);

    ~AudioPlayer();
private:
    SDL_AudioDeviceID device_id;

    SDL_AudioSpec properties;

    std::list<SoundGenerator> sound_generators;
};