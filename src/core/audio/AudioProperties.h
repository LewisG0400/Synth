#pragma once

#include <SDL2/SDL.h>

typedef struct AudioProperties {
    // This controls the DSP frequency of the playback
    int frequency;
    // This controls the number of channels (1 mono, 2 stereo etc)
    int n_channels;
    // This controls the size of the audio buffer
    Uint16 samples;
} AudioProperties;