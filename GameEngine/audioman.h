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

	static int runSFX(std::string audioname, int volume, Uint8 channels);
	static int runmusic(std::string audioname, int volume, Uint8 channels, bool loop);

	static int channelDone(int channel);

	/// PLANNED OUTCOME ///

	// make code to check = what channels are being utilised if possible??? (done but if reusing channels, makes channel next one!)

	// allow for more audio channels to be utilised: Mix_AllocateChannels(16);  (completed, set to 32 channels currently)

	// fade outs via the two channels for "Mix_FadeInMusic" & "Mix_FadeOutMusic" // make channels 0 & 1 exclusively for music

	// set volume post audio playing

	// make programming check how long audio file is and set up to end audio at audio end... (already does that :) )



	//change the string to audio library

	//stop music function
};

