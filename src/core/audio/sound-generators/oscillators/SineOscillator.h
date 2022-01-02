#pragma once

#include "Oscillator.h"

class SineOscillator : public Oscillator {
public:
    void putSound(Sint16 *stream, int stream_size, int frequency, int volume) override;
};