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
	static int runAudio(std::string audioname, int volume);
};

