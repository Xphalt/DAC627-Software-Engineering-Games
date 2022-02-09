#pragma once
#include "gameobject.h"
#include "SDL_mixer.h"
#include <map>

class audiolibrary
{
public:
	audiolibrary();
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

};
