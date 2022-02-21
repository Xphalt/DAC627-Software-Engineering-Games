#pragma once
#include "gameobject.h"
#include "SDL_mixer.h"
#include <map>
#include "SDL.h"
#include "SDL_audio.h"

#include <iostream>
#include <windows.h>
#include <string>

class audiolib
{
    public:
        //audiolib();
        //static int runAudio(std::string audioname, int volume);
        void initialiselibrary();

        enum audiotype { MUSIC, SFX, NUM_OF_TYPES };
        enum SFXcomponent { PLAYER, ENEMY, UI, NUM_OF_COMPS };
        enum SFXtype { JUMP, DAMAGE, COLLECTION, NUM_OF_SFXTYPES };
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

