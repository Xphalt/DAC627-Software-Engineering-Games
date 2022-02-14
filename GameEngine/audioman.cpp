#include "audioman.h"

int audioman::runAudio(std::string audioname, int volume)
{
    SDL_Init(SDL_INIT_AUDIO);

    // load WAV file
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;

    // drag the sound in to the folder audiolib.cpp is in 

    // open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    std::string fileInput = audioname + ".wav";
    Mix_Chunk* music = Mix_LoadWAV(fileInput.c_str());

    //music = Mix_LoadWAV("MusicIdea.WAV");

    if (Mix_PlayChannel(-1, music, 0) == -1)
    {
        printf("\nMix_PlayChannel: %s\n", Mix_GetError());
    }

    //set the sound's volume
    music->volume = volume; // if an error pops up a break point here, that usually means you arent correctly naming the song you want to use!
    // TESTING //std::cout << "\nMusic Volume is at: " + std::to_string(music->volume);


    Mix_PlayingMusic();

    // keep window open long enough to hear the sound
    //SDL_Delay(100000);

    // clean up
    SDL_CloseAudioDevice(deviceId);
    SDL_Quit();

    return(0);
}