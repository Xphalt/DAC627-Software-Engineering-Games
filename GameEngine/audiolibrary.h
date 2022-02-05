#pragma once

#include "gameobject.h"

class audiolibrary
{
public:
	audiolibrary();
	//InitialiseLibrary();

	enum audiotype {MUSIC, SFX, NUM_OF_TYPES};
	enum SFXComponent {PLAYER, ENEMY, UI, NUM_OF_COMPS};
	enum SFXType {JUMP, DAMAGE, COLLECTION, NUM_OF_SFXTYPES};
	enum MusicType { MENU, LEVEL, COMBAT, NUM_OF_MUSICTYPES };

private:
	//dictionary(audiotype, dictionary(SFXComponent, dictionary(SFXType, audiofile))) SFXLibrary;

	//dictionary(audiotype, dictionary(MusicType, audiofile)) musiclibrary;

	//char* SFXPath = "assets/audio/sfx";
	//char* musicPath = "assets/audio/music";

};

