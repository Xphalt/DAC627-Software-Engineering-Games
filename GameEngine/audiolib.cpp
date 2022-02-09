#include "audiolib.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_audio.h"

#include <iostream>
#include <windows.h>

//class audiolib
//{
//public:
    int audiolib::runAudio()
    {
        SDL_Init(SDL_INIT_AUDIO);

        // test its working
        OutputDebugString((LPCWSTR)"im working"); 
        std::cout << "Audio Working";


        // load WAV file

        SDL_AudioSpec wavSpec;
        Uint32 wavLength;
        Uint8* wavBuffer;

        SDL_LoadWAV("MusicIdea.wav", &wavSpec, &wavBuffer, &wavLength); // drag the sound in to the folder audiolib.cpp is in

        // open audio device

        SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

        // play audio

        int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
        SDL_PauseAudioDevice(deviceId, 0);

        // keep window open enough to hear the sound

        SDL_Delay(3000);

        // clean up

        SDL_CloseAudioDevice(deviceId);
        SDL_FreeWAV(wavBuffer);
        SDL_Quit();

        return(0);
    }
//};