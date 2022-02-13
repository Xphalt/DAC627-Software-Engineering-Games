#include "audiolib.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_audio.h"

#include <iostream>
#include <windows.h>

//class audiolib
//{
//public:
    int audiolib::runAudio(int audioname, int volume)
    {
        SDL_Init(SDL_INIT_AUDIO);

        // test its working
        std::cout << "Audio Working";

        enum audioname {idk, MusicIdea };


        // load WAV file
        SDL_AudioSpec wavSpec;
        Uint32 wavLength;
        Uint8* wavBuffer;

        //SDL_MixAudioFormat(wavBuffer, wavBuffer, wavLength, wavLength, 0.5); // trying to use this to affect audio

        SDL_LoadWAV("MusicIdea.wav", &wavSpec, &wavBuffer, &wavLength); // drag the sound in to the folder audiolib.cpp is in

        // open audio device

        SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

        //please god, please set the volume
        SDL_AudioFormat* format;
        Uint8* mixData;

        /*SDL_MixAudioFormat(wavBuffer, wavBuffer, wavLength, wavLength, 0.001);*/

        // play audio

        int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
        SDL_PauseAudioDevice(deviceId, 0);

        // keep window open enough to hear the sound

        SDL_Delay(100000);

        // clean up

        SDL_CloseAudioDevice(deviceId);
        SDL_FreeWAV(wavBuffer);
        SDL_Quit();

        return(0);
    }
//};