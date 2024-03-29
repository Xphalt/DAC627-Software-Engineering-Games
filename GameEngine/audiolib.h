#pragma once
#include "gameobject.h"
#include "SDL_mixer.h"
#include <map>
#include "SDL.h"
#include "SDL_audio.h"

#ifdef _WIN32

#include <iostream>
#include <windows.h>
#include <string>

class audiolib
{
    public:
        //audiolib();
        //static int runAudio(std::string audioname, int volume);
        void initialiselibrary();

        char** directory_files(const char* path, size_t* size_return);
        /*vector<string> get_all_files_full_path_within_folder(string folder);*/

        enum audiotype { MUSIC, SFX, NUM_OF_TYPES };
        enum SFXcomponent { PLAYER, ENEMY, UI, NUM_OF_COMPS };
        enum SFXtype { JUMP, DAMAGEENEMY, PLAYERHURT, SELECT, BACK, DASH, PLAYERMELEE, PLAYERRANGEDATTACK, PICKUP, HOTKEY1, HOTKEY2, HOTKEY3, EXPLOSION, HEAL, POWERUP, SPELL, BOSSCHARGE, BOSSRIPPLE, BOSSPROJECTILE, COLLECTION, NUM_OF_SFXTYPES };
        enum musictype { MENU, LEVEL, COMBAT, NUM_OF_MUSICTYPES };

    private:
        std::map < audiotype, std::map < SFXcomponent, std::map < SFXtype, Mix_Chunk >>> SFXlibrary;

        std::map < audiotype, std::map < musictype, Mix_Music >> musiclibrary;

        const char* SFXPath[17] = { "assets/audio/sfx" };
        const char* musicPath[19] = { "assets/audio/music" };

        bool loadfiles();

        // make code to check for .WAV files and pick them up / put them in to an enum
        // find way to associate enum with names...
        // ^ this up above is so users don't need to remember the names of all the sound files


};

#endif // _WIN32