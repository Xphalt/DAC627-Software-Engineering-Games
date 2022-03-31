#include "audioman.h"
#include <string.h>
#include <regex>
#include <stdlib.h>


//WCHAR* FILEDIR = ".\\Audio"; // \\*.wav
//WCHAR* FILEEXT = "*.wav";
//WCHAR* SFILEPATH = FILEDIR + "\\" + FILEEXT;
//LPCWSTR FILEPATH = SFILEPATH.c_str(); // \\*.wav

const char* SFILEPATH = ".\\Audio"; // \\*.wav
const char* FILEEXT = "*.*";
// const std::regex AUDIO_FILE_EXT("*.*");
// const std::regex AUDIO_FILE_EXT("*\.(mp3|wav|ogg|mid|flac)");
const char* AUDIO_FILE_EXT("*.(mp3|wav|ogg|mid|flac)");
const int MAX_LEN = 200;

// strcat(SFILEPATH, "\\");
// strcat(SFILEPATH, FILEEXT);
// wchar_t WFILEPATH[200];
// std::size_t mbstowcs(WFILEPATH, SFILEPATH, strlen(SFILEPATH)+1);//Plus null
// LPCWSTR FILEPATH = wtext;

 //char text[] = "something";
 //wchar_t wtext[20];
 //mbstowcs(wtext, text, strlen(text)+1);//Plus null
 //LPWSTR ptr = wtext;



// if any questions about this ask Morgan Sands

///// base calls for all functions! /////
    //audioman::runsearchedaudiofile(7, 69, 1);
    //audioman::runsearchedmusicfile(11, 69, 4, 1);
    //audioman::runSFX("Jump", 69, 1); // unironically 69 is a really good medium volume...
    //audioman::runSFXlist(2 69, 2);
    //audioman::runmusic("Idle", 128, 4, 1);
    //audioman::runmusiclist(1, 69, -1, 0);
    //audioman::volmusic(0);
    //audioman::endmusic(0);


boolean isAudioFile(WIN32_FIND_DATA file)
{
    char fileName[MAX_LEN];
    size_t i;
    wcstombs_s(&i, fileName, MAX_LEN, file.cFileName, wcslen(file.cFileName) + 1);

   if(std::strstr(fileName, ".wav") != NULL) { 
      return true;
   } 
   else if (std::strstr(fileName, ".mp3") != NULL) { 
      return true;
   }
   else if (std::strstr(fileName, ".mp3") != NULL) {
       return true;
   }
   else if (std::strstr(fileName, ".ogg") != NULL) {
       return true;
   }
   else if (std::strstr(fileName, ".flac") != NULL) {
       return true;
   }
   else if (std::strstr(fileName, ".mid") != NULL) {
       return true;
   }

   return false;
   // return(regex_match(fileName, m, std::regex(AUDIO_FILE_EXT)));
}


LPCWSTR getFilePath()
{
    char tempFilePath[200];
    size_t retVal;
    strcpy_s(tempFilePath, 200, SFILEPATH);
    strcat_s(tempFilePath, "\\");
    strcat_s(tempFilePath, FILEEXT);
    wchar_t WFILEPATH[200];
    mbstowcs_s(&retVal, WFILEPATH, 200, tempFilePath, strlen(tempFilePath)+1);//Plus null // std::size_t
    LPCWSTR FILEPATH = WFILEPATH; // \\*.wav
    return(FILEPATH);
}


std::string getAudioFilePath(std::string bufferAudioFile)
{
    std::string audioFilePath = SFILEPATH;
    audioFilePath += "\\";
    audioFilePath += bufferAudioFile;

    return(audioFilePath);
}


std::string getWAudioFilePath(WCHAR* bufferAudioFile)
{
    std::wstring wAudioFile(bufferAudioFile);
    std::string audioFile(wAudioFile.begin(), wAudioFile.end());

    return(getAudioFilePath(audioFile));
}



// file searched audio
void audioman::runsearchedaudiofile(int fileNumber, int volume, Uint8 channels)
{
    TCHAR Buffer[BUFSIZE];
    DWORD dwRet;
    dwRet = GetCurrentDirectory(BUFSIZE, Buffer);

    WIN32_FIND_DATA ffd;
    LARGE_INTEGER filesize;
    TCHAR szDir[MAX_PATH];
    HANDLE hFind = INVALID_HANDLE_VALUE;
    DWORD dwError = 0;

    // Find the first file in the directory.

    hFind = FindFirstFile(getFilePath(), &ffd); // FILEPATH
    int fileCount = 1;

    if (INVALID_HANDLE_VALUE == hFind)
    {
        std::cout << "FindFirstFile" << std::endl;
        return;
    }

    // List all the files in the directory with some info about them.

    do
    {
        if (isAudioFile(ffd) && fileCount == fileNumber)
        {
            runfoundaudio(ffd.cFileName, volume, channels);
        }

        fileCount++;
    } while (FindNextFile(hFind, &ffd) != 0);

    // incase we need to check for errors
    dwError = GetLastError();

    // close up the system
    FindClose(hFind);
    return;
}

int audioman::runfoundaudio(WCHAR* bufferSoundFile, int volume, Uint8 channels)
{
    // drag the sound in to the folder in which audioman.cpp is in //

    //converting one data type to another
    // std::wstring wSoundFile(bufferSoundFile);
    // std::string soundFile(wSoundFile.begin(), wSoundFile.end());
    // std::string SoundFilePath = SFILEPATH;
    // SoundFilePath += "\\";
    // SoundFilePath += soundFile;

    std::string SoundFilePath = getWAudioFilePath(bufferSoundFile);



    //initialise audio
    SDL_Init(SDL_INIT_AUDIO);

    //set amount of channels to be used
    Mix_AllocateChannels(32);

    // load WAV file
    SDL_AudioSpec wavSpec;

    // open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // inputting .wav in to audio
    Mix_Chunk* audio = Mix_LoadWAV(SoundFilePath.c_str());

    // play sound
    Mix_PlayChannel(channels, audio, 0);


    //set the sound's volume
    audio->volume = volume; // if an error pops up a break point here, that usually means you've done someting wrong with your input of the function!

    // clean up
    SDL_CloseAudioDevice(deviceId);

    return(0);
}

// file searched music
void audioman::runsearchedmusicfile(int fileNumber, int volume, int loopamount, int fadeintime)
{
    TCHAR Buffer[BUFSIZE];
    DWORD dwRet;
    dwRet = GetCurrentDirectory(BUFSIZE, Buffer);

    WIN32_FIND_DATA ffdm;
    LARGE_INTEGER filesize;
    TCHAR szDir[MAX_PATH];
    HANDLE hFind = INVALID_HANDLE_VALUE;
    DWORD dwError = 0;

    // Find the first file in the directory.

    hFind = FindFirstFile(getFilePath(), &ffdm);
    int fileCount = 1;

    if (INVALID_HANDLE_VALUE == hFind)
    {
        std::cout << "FindFirstFile" << std::endl;
        return;
    }

    // List all the files in the directory with some info about them.

    do
    {
        //if (!(ffdm.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        //{
        //    filesize.LowPart = ffdm.nFileSizeLow;
        //    filesize.HighPart = ffdm.nFileSizeHigh;
        //}

        if (fileCount == fileNumber)
        {
            runfoundmusic(ffdm.cFileName, volume, loopamount, fadeintime);
        }

        fileCount++;
    } while (FindNextFile(hFind, &ffdm) != 0);

    // incase we want to find any errors
    dwError = GetLastError();

    // close up the system
    FindClose(hFind);
    return;
}


int audioman::runfoundmusic(WCHAR* bufferMusicFile, int volume, int loopamount, int fadeintime)
{
    // drag the sound in to the folder in which audioman.cpp is in //

    //converting one data type to another
    // std::wstring wMusicFile(bufferMusicFile);
    // std::string musicFile(wMusicFile.begin(), wMusicFile.end());
    // std::string musicFilePath = SFILEPATH;
    // musicFilePath += "\\";
    // musicFilePath += musicFile;

    std::string musicFilePath = getWAudioFilePath(bufferMusicFile);



    // initialise audio
    SDL_Init(SDL_INIT_AUDIO);

    // load WAV file
    SDL_AudioSpec wavSpec;

    // open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // inputting audio to the file
    //std::string fileInput = musicFile; //  + ".wav"
    Mix_Music* music = Mix_LoadMUS(musicFilePath.c_str());

    // play music
    Mix_FadeInMusic(music, loopamount, fadeintime);

    //set the music's volume
    Mix_VolumeMusic(volume); // if an error pops up a break point around here, that usually means you arent correctly naming the song you want to use!

    // clean up // this stuff is for if it is a sound effect
    SDL_CloseAudioDevice(deviceId);

    return(0);
}

// traditional text and name based method
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
    std::string musicFilePath = getAudioFilePath(soundname);

    musicFilePath += ".wav";
    Mix_Chunk* audio = Mix_LoadWAV(musicFilePath.c_str());

    // play sound
    Mix_PlayChannel(channels, audio, 0);


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
    std::string audioFilePath = getAudioFilePath(audioname);

    audioFilePath += ".wav";
    Mix_Music* music = Mix_LoadMUS(audioFilePath.c_str());

    // play music
    Mix_FadeInMusic(music, loopamount, fadeintime);

    //set the music's volume
    Mix_VolumeMusic(volume); // if an error pops up a break point around here, that usually means you arent correctly naming the song you want to use!

    // clean up // this stuff is for if it is a sound effect
    SDL_CloseAudioDevice(deviceId);

    return(0);
}


// music suppliment functions (just stuff made simplified to use elsewhere)
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

    //set the sound's volume
    music->volume = volume; // if an error pops up a break point here, that usually means you arent correctly naming the song you want to use!

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

    //set the music's volume
    Mix_VolumeMusic(volume); // if an error pops up a break point around here, that usually means you arent correctly naming the song you want to use!

    // clean up
    SDL_CloseAudioDevice(deviceId);

    return(0);
}