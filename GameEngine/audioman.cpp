#include "audioman.h"

int audioman::runAudio(std::string audioname, int volume, Uint8 channels)
{
    // drag the sound in to the folder audiolib.cpp is in //

    SDL_Init(SDL_INIT_AUDIO);

    Mix_AllocateChannels(32);

    // load WAV file
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;

    // open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // inputting audio to the file
    std::string fileInput = audioname + ".wav";
    Mix_Chunk* music = Mix_LoadWAV(fileInput.c_str());

    //music = Mix_LoadWAV("MusicIdea.WAV");

    // musical error check
    //if (Mix_PlayChannel(channels, music, 0) == -1) //(was -1)
    //{
    //    printf("\nMix_PlayChannel: %s\n", Mix_GetError());
    //}

    //Mix_PlayChannel(Mix_Playing(-1)+1, music, 0);
    Mix_PlayChannel(channels, music, 0);
    printf("\nMix_PlayChannel: %s\n", Mix_GetError());

    //printf("\nMix_PlayChannel: ", Mix_GetError());

    //set the sound's volume
    music->volume = volume; // if an error pops up a break point here, that usually means you arent correctly naming the song you want to use!
    // TESTING //std::cout << "\nMusic Volume is at: " + std::to_string(music->volume);

    //play the music
    Mix_PlayingMusic();

    Mix_SetMusicPosition(5.0);

    // keep window open long enough to hear the sound
    //SDL_Delay(1000);

    // clean up // this stuff is for if it is a sound effect
    SDL_CloseAudioDevice(deviceId);
    //SDL_Quit();

    return(0);
}

/// <summary>
///             THIS IS WHERE THE NEW STUFF COMES IN TO IT!!!
/// </summary>

int audioman::runmusic(std::string audioname, int volume, Uint8 channels, bool loop)
{
    // drag the sound in to the folder audiolib.cpp is in //

    SDL_Init(SDL_INIT_AUDIO);

    Mix_AllocateChannels(32);

    // load WAV file
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;

    // open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // inputting audio to the file
    std::string fileInput = audioname + ".wav";
    Mix_Chunk* music = Mix_LoadWAV(fileInput.c_str());

    //music = Mix_LoadWAV("MusicIdea.WAV");

    // musical error check
    //if (Mix_PlayChannel(channels, music, 0) == -1) //(was -1)
    //{
    //    printf("\nMix_PlayChannel: %s\n", Mix_GetError());
    //}

    Mix_PlayChannel(Mix_Playing(-1) + 1, music, 0);
    printf("\nMix_PlayChannel: %s\n", Mix_GetError());

    //set the sound's volume
    music->volume = volume; // if an error pops up a break point here, that usually means you arent correctly naming the song you want to use!
    // TESTING //std::cout << "\nMusic Volume is at: " + std::to_string(music->volume);

    //play the music
    Mix_PlayingMusic();

    // keep window open long enough to hear the sound
    //SDL_Delay(100000);

    // clean up // this stuff is for if it is a sound effect
    SDL_CloseAudioDevice(deviceId);
    //SDL_Quit();

    return(0);
}

int audioman::runSFX(SFXtype audioname, int volume, Uint8 channels)
{
    // drag the sound in to the folder audiolib.cpp is in //

    std::string sound;

    switch (audioname) {
    case JUMP:
        sound = "jump";
        break;
    case DAMAGEENEMY:
        sound = "enemyHurt";
        break;
    case PLAYERHURT:
        sound = "playerHurt";
        break;
    case SELECT:
        sound = "Select";
        break;
    case BACK:
        sound = "Back";
        break;
    case DASH:
        sound = "Dash";
        break;
    case PLAYERMELEE:
        sound = "Melee";
        break;
    case PLAYERRANGEDATTACK:
        sound = "playerHurt";
        break;
    case PICKUP:
        sound = "Pickup";
        break;
    case HOTKEY1:
        sound = "Hotkey 1";
        break;
    case HOTKEY2:
        sound = "Hotkey 2";
        break;
    case HOTKEY3:
        sound = "Hotkey 3";
        break;
    case EXPLOSION:
        sound = "Explosion";
        break;
    case HEAL:
        sound = "Heal";
        break;
    case POWERUP:
        sound = "PowerUp";
        break;
    case SPELL:
        sound = "Spell";
        break;
    case BOSSCHARGE:
        sound = "Boss Charge Attack";
        break;
    case BOSSRIPPLE:
        sound = "Ripple Attack";
        break;
    case BOSSPROJECTILE:
        sound = "Projectile";
        break;
    case COLLECTION:
        sound = "Pickup";
        break;
    }

    SDL_Init(SDL_INIT_AUDIO);

    Mix_AllocateChannels(32);

    // load WAV file
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;

    // open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // inputting audio to the file
    std::string fileInput = sound + ".wav";
    Mix_Chunk* music = Mix_LoadWAV(fileInput.c_str());

    //music = Mix_LoadWAV("MusicIdea.WAV");

    // musical error check
    //if (Mix_PlayChannel(channels, music, 0) == -1) //(was -1)
    //{
    //    printf("\nMix_PlayChannel: %s\n", Mix_GetError());
    //}

    Mix_PlayChannel(Mix_Playing(-1) + 1, music, 0);
    printf("\nMix_PlayChannel: %s\n", Mix_GetError());

    //set the sound's volume
    music->volume = volume; // if an error pops up a break point here, that usually means you arent correctly naming the song you want to use!
    // TESTING //std::cout << "\nMusic Volume is at: " + std::to_string(music->volume);

    //play the music
    Mix_PlayingMusic();

    // keep window open long enough to hear the sound
    SDL_Delay(100000);

    // clean up // this stuff is for if it is a sound effect
    SDL_CloseAudioDevice(deviceId);
    //SDL_Quit();

    return(0);
}

int audioman::channelDone(int channel)
{
    printf("channel %d finished playing.\n", channel);
    
        // set the callback for when a channel stops playing

        //Mix_ChannelFinished(channelDone);

        return(0);
}

