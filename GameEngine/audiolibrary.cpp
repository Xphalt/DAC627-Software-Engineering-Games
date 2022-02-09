#include "audiolibrary.h"

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