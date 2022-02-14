#include "audiolib.h"


//using namespace std;

//class audiolib
//{
//public:
    //audiolib::audiolib()
    //{

    //}

void audiolib::initialiselibrary()
{
    //loadfiles();
}

bool audiolib::loadfiles()
{
    //Load the music
    //music = Mix_LoadMUS( "beat.wav" );

    //if there was a problem loading the music
    //if (music == NULL)
    //{
    //     return false
    //}

    //Load the sound effects
    //SFXlibrary[SFX][PLAYER].insert(std::makepair(DAMAGE, Mix_LoadWAV("assets/audio/sfx/player/damage/playerHurt.WAV")));
    //SFXlibrary.insert(std::make_pair(SFX, std::make_pair(PLAYER, std::make_pair(JUMP, Mix_LoadWAV(SFXPath + "/player/damage/playerJump.WAV")))));

    //scratch = Mix_LoadWAV("scratch.wav");
    //high = Mix_LoadWAV("high.WAV");
    //med = Mix_LoadWAV("medium.wav");
    //low = Mix_LoadWAV("low.wav");

    //if there was a problem loading the sound effects
    //if ((scratch == NULL) || (high = NULL) || (med == NULL) || ( low == NULL))
    //{
    //    return false;
    //}

    return true;
}

//int audiolib::runAudio(std::string audioname, int volume)
//{
//    SDL_Init(SDL_INIT_AUDIO);
//
//    // load WAV file
//    SDL_AudioSpec wavSpec;
//    Uint32 wavLength;
//
//    // drag the sound in to the folder audiolib.cpp is in 
//
//    // open audio device
//    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
//
//    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
//
//    std::string fileInput = audioname + ".wav";
//    Mix_Chunk* music = Mix_LoadWAV(fileInput.c_str());
//
//    //music = Mix_LoadWAV("MusicIdea.WAV");
//
//    if (Mix_PlayChannel(-1, music, 0) == -1) 
//    {
//        printf("\nMix_PlayChannel: %s\n", Mix_GetError());
//    }
//
//    //set the sound's volume
//    music->volume = volume; // if an error pops up a break point here, that usually means you arent correctly naming the song you want to use!
//    // TESTING //std::cout << "\nMusic Volume is at: " + std::to_string(music->volume);
//
//
//    Mix_PlayingMusic();
//
//    // keep window open long enough to hear the sound
//    //SDL_Delay(100000);
//
//    // clean up
//    SDL_CloseAudioDevice(deviceId);
//    SDL_Quit();
//
//    return(0);
//}
//};