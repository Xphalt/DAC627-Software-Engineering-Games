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
        //Uint8 *mixData = new Uint8(wavLength);
        //extern Uint8 mixData; // was: extern const Uint8* mixData;





        std::cout << "\nwavLength: " + std::to_string(wavLength);
        std::cout << "\nsizeof(wavBuffer): " + std::to_string(sizeof(wavBuffer));
        std::cout << "\nsizeof(wavBuffer[0]): " + std::to_string(sizeof(wavBuffer[0]));
        std::cout << "\nsizeof(wavBuffer)/sizeof(wavBuffer[0]): " + std::to_string(sizeof(wavBuffer)/sizeof(wavBuffer[0]));
        //std::cout << "\nsizeof(mixData): " + std::to_string(sizeof(mixData));
        //std::cout << "\nsizeof(mixData[0]): " + std::to_string(sizeof(mixData[0]));
        //std::cout << "\nsizeof(mixData)/sizeof(mixData[0]): " + std::to_string(sizeof(mixData)/sizeof(mixData[0]));

        //SDL_memset(mixData, 0, wavLength);
        //int egg = Mix_Volume(-1, volume);


        Mix_VolumeMusic(volume);
        int eggu = Mix_VolumeMusic(-1);        
        std::cout << "\nMusic Volume is at: " + std::to_string(eggu);

        
        //SDL_MixAudioFormat(&mixData, wavBuffer, wavSpec.format, wavLength, vol);
        //try SDL_MixAudio???        

        //SDL_MixAudio(mixData, wavBuffer, wavLength, vol);
        //SDL_MixAudio(mixData, wavBuffer, 5, 1);

        // play audio
        //int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
        //SDL_PauseAudioDevice(deviceId, 0);      

        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

        //Mix_Music* music = Mix_LoadMUS("MusicIdea.WAV");
        Mix_Chunk* music = Mix_LoadWAV("MusicIdea.WAV");

        if (Mix_PlayChannel(-1, music, 0) == -1) {
            printf("\nMix_PlayChannel: %s\n", Mix_GetError());
        }

        printf("\nmusic is%s playing.\n", Mix_PlayingMusic()?"":" not");
        music.Volume(eggu);

        Mix_PlayingMusic();

        // keep window open enough to hear the sound
        SDL_Delay(100000);

        // clean up
        SDL_CloseAudioDevice(deviceId);
        SDL_FreeWAV(wavBuffer);
        //SDL_FreeWAV(mix);
        SDL_Quit();

        return(0);
    }
//};