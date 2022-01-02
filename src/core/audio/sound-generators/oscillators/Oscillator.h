#pragma once

#include <math.h>
#include <SDL2/SDL_types.h>

#include "../../AudioProperties.h"

class Oscillator {
public:
    virtual void putSound(Sint16 *stream, AudioProperties properties, int frequency, int volume);
protected:
    int master_volume;
};