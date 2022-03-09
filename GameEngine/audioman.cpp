#include "audioman.h"


//const std::string FILEPATH = ".\DAC627-Software-Engineering-Games\GameEngine";
LPCWSTR FILEPATH = L".\\*.wav";








void audioman::searchfiles()
{
    TCHAR Buffer[BUFSIZE];
    DWORD dwRet;
    dwRet = GetCurrentDirectory(BUFSIZE, Buffer);

    //std::cout << "Working directory: " + Buffer;

    std::cout << "Working directory: ";

    std::cout << Buffer;

    //printf(



    WIN32_FIND_DATA ffd;
    LARGE_INTEGER filesize;
    TCHAR szDir[MAX_PATH];
    //size_t length_of_arg;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    DWORD dwError = 0;

    // If the directory is not specified as a command-line argument,
    // print usage. // KEEP THIS HERE IF ISSUE COMES UP AND WE DONT KNOW WHAT IT IS!!!!!

    // Check that the input path plus 3 is not longer than MAX_PATH.
    // Three characters are for the "\*" plus NULL appended below.

    //StringCchLength(FILEPATH, MAX_PATH, &length_of_arg);

 /*   if (FILEPATH.wcslen() > (MAX_PATH - 3))
    {
        _tprintf(TEXT("\nDirectory path is too long.\n"));
        return (-1);
    }*/

    //_tprintf(TEXT("\nTarget directory is %s\n\n"), argv[1]);

    // Prepare string for use with FindFile functions.  First, copy the
    // string to a buffer, then append '\*' to the directory name.

    //StringCchCopy(szDir, MAX_PATH, FILEPATH);
    //StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

    // Find the first file in the directory.

    hFind = FindFirstFile(FILEPATH, &ffd);

    if (INVALID_HANDLE_VALUE == hFind)
    {
        std::cout << "FindFirstFile" << std::endl;
        return;
    }

    // List all the files in the directory with some info about them.

    do
    {
        if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            /*_tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);*/
        }
        else
        {
            filesize.LowPart = ffd.nFileSizeLow;
            filesize.HighPart = ffd.nFileSizeHigh;
            /*_tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);*/
            _tprintf(ffd.cFileName, "\n");
        }
    } while (FindNextFile(hFind, &ffd) != 0);

    dwError = GetLastError();
    if (dwError != ERROR_NO_MORE_FILES)
    {
        /*DisplayErrorBox(TEXT("FindFirstFile"));*/
    }

    FindClose(hFind);
    return;
}

//std::wstring string_to_wstring(const std::string& text) {
//    return std::wstring(text.begin(), text.end());
//}







///ACTUAL RUNNNING OF AUDIO CODE ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int audioman::runSFX(std::string soundname, int volume, Uint8 channels)
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
    std::string fileInput = soundname + ".wav";
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