#include "audioman.h"

int audioman::runSFX(std::string audioname, int volume, Uint8 channels)
{
    // drag the sound in to the folder in which audioman.cpp is in //

    //initialise audio
    SDL_Init(SDL_INIT_AUDIO);

    //set amount of channels to be used
    Mix_AllocateChannels(32);

    // load WAV file
    SDL_AudioSpec wavSpec;

    // open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // inputting audio to the file
    std::string fileInput = audioname + ".wav";
    Mix_Chunk* audio = Mix_LoadWAV(fileInput.c_str());

    // play sound
    Mix_PlayChannel(channels, audio, 0);
    printf("\nMix_PlayChannel: %s\n", Mix_GetError());


    //set the sound's volume
    audio->volume = volume; // if an error pops up a break point here, that usually means you arent correctly naming the song you want to use!

    // clean up
    SDL_CloseAudioDevice(deviceId);

    return(0);
}

int audioman::runmusic(std::string audioname, int volume, int loopamount, int fadeintime)
{
    // drag the sound in to the folder in which audioman.cpp is in //

    SDL_Init(SDL_INIT_AUDIO);

    // load WAV file
    SDL_AudioSpec wavSpec;

    // open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // inputting audio to the file
    std::string fileInput = audioname + ".wav";
    Mix_Music* music = Mix_LoadMUS(fileInput.c_str());

    // play music
    Mix_FadeInMusic(music, loopamount, fadeintime);
    printf("\nMix_PlayChannel: %s\n", Mix_GetError());

    //set the music's volume
    Mix_VolumeMusic(volume); // if an error pops up a break point around here, that usually means you arent correctly naming the song you want to use!

    // clean up // this stuff is for if it is a sound effect
    SDL_CloseAudioDevice(deviceId);

    return(0);
}

int audioman::endmusic(int fadeouttime)
{
    Mix_FadeOutMusic(fadeouttime);
    return 0;
}

int audioman::volmusic(int volume)
{
    Mix_VolumeMusic(volume);
    return 0;
}

// enum/list based options fot those who just want to use only the base in engine sounds rather then making and dragging in to the folder in their own!

int audioman::runSFXlist(int soundnum, int volume, Uint8 channels)
{
    std::string sound;

    //setting the int to the sound
    switch (soundnum) {
    case SFXtype::JUMP:
        sound = "Jump";
        break;
    case SFXtype::DAMAGEENEMY:
        sound = "enemyHurt";
        break;
    case SFXtype::PLAYERHURT:
        sound = "playerHurt";
        break;
    case SFXtype::SELECT:
        sound = "Select";
        break;
    case SFXtype::BACK:
        sound = "Back";
        break;
    case SFXtype::DASH:
        sound = "Dash";
        break;
    case SFXtype::PLAYERMELEE:
        sound = "Melee";
        break;
    case SFXtype::PLAYERRANGEDATTACK:
        sound = "playerHurt";
        break;
    case SFXtype::PICKUP:
        sound = "Pickup";
        break;
    case SFXtype::HOTKEY1:
        sound = "Hotkey 1";
        break;
    case SFXtype::HOTKEY2:
        sound = "Hotkey 2";
        break;
    case SFXtype::HOTKEY3:
        sound = "Hotkey 3";
        break;
    case SFXtype::EXPLOSION:
        sound = "Explosion";
        break;
    case SFXtype::HEAL:
        sound = "Heal";
        break;
    case SFXtype::POWERUP:
        sound = "PowerUp";
        break;
    case SFXtype::SPELL:
        sound = "Spell";
        break;
    case SFXtype::BOSSCHARGE:
        sound = "Boss Charge Attack";
        break;
    case SFXtype::BOSSRIPPLE:
        sound = "Ripple Attack";
        break;
    case SFXtype::BOSSPROJECTILE:
        sound = "Projectile";
        break;
    case SFXtype::COLLECTION:
        sound = "Pickup";
        break;
    }

    //initialise audio
    SDL_Init(SDL_INIT_AUDIO);

    //set amount of channels to be used
    Mix_AllocateChannels(32);

    // load WAV file
    SDL_AudioSpec wavSpec;

    // open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // inputting audio to the file
    std::string fileInput = sound + ".wav";
    Mix_Chunk* music = Mix_LoadWAV(fileInput.c_str());

    // play sound
    Mix_PlayChannel(Mix_Playing(-1) + 1, music, 0);
    printf("\nMix_PlayChannel: %s\n", Mix_GetError());

    //set the sound's volume
    music->volume = volume; // if an error pops up a break point here, that usually means you arent correctly naming the song you want to use!

    // keep window open long enough to hear the sound
    SDL_Delay(100000);

    // clean up 
    SDL_CloseAudioDevice(deviceId);

    return 0;
}

int audioman::runmusiclist(int audionum, int volume, int loopamount, int fadeintime)
{
    std::string audio;

    //setting the int to the sound
    switch (audionum) {
    case musictype::IDLE:
        audio = "Idle";
        break;
    case musictype::COMBAT:
        audio = "Combat";
        break;
    case musictype::MUSICIDEA:
        audio = "MusicIdea";
        break;
    case musictype::LEVELTHEME:
        audio = "LevelTheme";
        break;
    }

    // initialising audio
    SDL_Init(SDL_INIT_AUDIO);

    // load WAV file
    SDL_AudioSpec wavSpec;

    // open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // inputting audio to the file
    std::string fileInput = audio + ".wav";
    Mix_Music* music = Mix_LoadMUS(fileInput.c_str());

    // play music
    Mix_FadeInMusic(music, loopamount, fadeintime);
    printf("\nMix_PlayChannel: %s\n", Mix_GetError());

    //set the music's volume
    Mix_VolumeMusic(volume); // if an error pops up a break point around here, that usually means you arent correctly naming the song you want to use!

    // clean up
    SDL_CloseAudioDevice(deviceId);

    return(0);
}