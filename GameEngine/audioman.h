#pragma once
#include "gameobject.h"
#include "SDL_mixer.h"
#include <map>
#include "SDL.h"
#include "SDL_audio.h"

#include <iostream>
#include <windows.h>
#include <string>

class audioman
{
public:
	static int runAudio(std::string audioname, int volume, Uint8 channels);

	static int runmusic(std::string audioname, int volume);
	static int runSFX(std::string audioname, int volume);

	/// PLANNED OUTCOME ///
	// static int runSFX(std::string SFXname, int volume, Audio Channel???); // note channels 0 & 1 are off-limits
	// static int runMusic(std::string songname, int volume, bool loop, Audio Channel???);
	// make code to check = what channels are being utilised if possible???

	// fade outs via the two channels for "Mix_FadeInMusic" & "Mix_FadeOutMusic"

	// make programming check how long audio file is and set up to end audio at audio end...


	//change the string to audio library

	//stop music function
};

