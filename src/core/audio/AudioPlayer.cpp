#include "AudioPlayer.h"

void updateData(void *unused, Uint8 *byteStream, int byteStreamLength);

AudioPlayer::AudioPlayer(AudioProperties desired_properties) {
    // Set the properties we want our output to have
    SDL_AudioSpec props;
    SDL_zero(props);
    props.freq = desired_properties.frequency;
    props.format = AUDIO_S16;
    props.channels = desired_properties.n_channels;
    props.samples = desired_properties.samples;
    props.callback = [] (void *sound_generators, Uint8 *byteStream, int byteStreamLength) {this->updateData(sound_generators, byteStream, byteStreamLength);};
    props.userdata = (void*) &this->sound_generators;

    // Open an audio device and get the properties of our audio
    this->device_id = SDL_OpenAudioDevice(NULL, false, &props, &this->properties, false);
    if(device_id < 0) {
        std::cout << "Error creating audio device." << std::endl;
    }

    SDL_PauseAudioDevice(device_id, 0);
}

void AudioPlayer::play() {
    SDL_PauseAudioDevice(device_id, 0);
}

void AudioPlayer::pause() {
    SDL_PauseAudioDevice(device_id, 1);
}

AudioPlayer::~AudioPlayer() {
    SDL_CloseAudioDevice(device_id);
}

void AudioPlayer::updateData(void *sound_generators, Uint8 *byteStream, int byteStreamLength) {
    Uint32 stream_size = byteStreamLength / sizeof(Sint16);
    Sint16 *stream = reinterpret_cast<Sint16*>(byteStream);

    auto generators = *static_cast<std::list<SoundGenerator>*>(sound_generators);

    for(int i = 0; i < stream_size; i += 1) {
        stream[i] = 32767 * (float)::rand() / ((float)RAND_MAX/2) - 1.0;
    }

    for(auto generator : generators) {
        generator.writeToStream(stream, this->properties, 440, 1);
    }
}