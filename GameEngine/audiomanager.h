#pragma once

#include "audiolibrary.h"

class audiomanager : audiolibrary
{
private:
	audiolibrary* aLib;

public:
	audiomanager();
	audiomanager(gameobject* go);

	void playSFX(audiotype, SFXcomponent, SFXtype);

	//void playMusic(aLib->AudioType at, aLib.MusicComponent mc, aLib.MusicType mt);
	
};

