#pragma once

#include "audiolibrary.h"

class audiomanager
{
private:
	audiolibrary* aLib;

public:
	audiomanager();
	audiomanager(gameobject* go);

	//void PlaySFX(aLib.AudioType at, aLib.SFXComponent sc, aLib.SFXType st);

	//void PlayMusic(aLib.AudioType at, aLib.MusicComponent mc, aLib.MusicType mt);

};

