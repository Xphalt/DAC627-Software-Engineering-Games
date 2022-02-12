#include "audiolibrary.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_audio.h"

#include <iostream>
//#include <windows.h>

audiolibrary::audiolibrary()
{

}

void audiolibrary::initialiselibrary()
{
    loadfiles();
}


bool audiolibrary::loadfiles()
{    
    //Load the music
    //music = Mix_LoadMUS( "beat.wav" );
    
    //If there was a problem loading the music
    /*if (music == NULL)
    {
        return false;    
    }*/

    //Load the sound effects
    SFXlibrary[SFX][PLAYER].insert(std::make_pair(DAMAGE, Mix_LoadWAV("assets/audio/sfx/player/damage/playerHurt.WAV")));
    //SFXlibrary.insert(std::make_pair(SFX, std::make_pair(PLAYER, std::make_pair(JUMP, Mix_LoadWAV(SFXPath + "/player/damage/playerJump.WAV")))));

    //scratch = Mix_LoadWAV( "scratch.wav" );
    //high = Mix_LoadWAV( "high.wav" );
    //med = Mix_LoadWAV( "medium.wav" );
    //low = Mix_LoadWAV( "low.wav" );
    
    //If there was a problem loading the sound effects
    /*if ((scratch == NULL) || (high == NULL) || (med == NULL) || (low == NULL))
    {
        return false;    
    }*/
    
    //If everything loaded fine
    return true; 
}

int audiolibrary::runaudio()
{
    SDL_Init(SDL_INIT_AUDIO);

    // Test if sound is working
    std::cout << "Audio Working";

    // Load .WAV file
    SDL_AudioSpec wavspec;
    Uint32 wavlength;
    Uint8* wavbuffer;

    SDL_LoadWAV("MusicIdea.wav", &wavspec, &wavbuffer, &wavlength); // drag the sound file in to the folder audiolib.cpp

    // Open Audio Device
    SDL_AudioDeviceID deviceid = SDL_OpenAudioDevice(NULL, 0, &wavspec, NULL, 0);

    // Play Audio
    int success = SDL_QueueAudio(deviceid, wavbuffer, wavlength);
    SDL_PauseAudioDevice(deviceid, 0);

    // pls rkeep window open long enough to hear the sound
    SDL_Delay(3000);

    // Clean Up
    SDL_CloseAudioDevice(deviceid);
    SDL_FreeWAV(wavbuffer);
    SDL_Quit();

    return(0);
}