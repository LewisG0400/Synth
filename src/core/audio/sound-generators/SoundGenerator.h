#pragma once

#include <list>

#include "../sound-modifiers/SoundModifier.h"
#include "oscillators/Oscillator.h"

class SoundGenerator {
public:
    virtual void writeToStream(Sint16 *stream, SDL_AudioSpec properties, int frequency, int volume);
private:
    std::list<Oscillator> oscillators;
    std::list<SoundModifier> modifiers;
};