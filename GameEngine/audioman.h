#pragma once
#include "gameobject.h"
#include "SDL_mixer.h"
#include <map>
#include "SDL.h"
#include "SDL_audio.h"

#include <iostream>
#include <windows.h>

#include <string>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#pragma comment(lib, "User32.lib")

#define BUFSIZE MAX_PATH

//using namespace std;


class audioman
{
public:
	// enums
	enum musictype { IDLE, COMBAT, MUSICIDEA, LEVELTHEME };
	enum SFXtype { JUMP, DAMAGEENEMY, PLAYERHURT, SELECT, BACK, DASH, PLAYERMELEE, PLAYERRANGEDATTACK, PICKUP, HOTKEY1, HOTKEY2, HOTKEY3, EXPLOSION, HEAL, POWERUP, SPELL, BOSSCHARGE, BOSSRIPPLE, BOSSPROJECTILE, COLLECTION, NUM_OF_SFXTYPES };

	// SFX running functions
	static int runSFX(std::string soundname, int volume, Uint8 channels);
	static int runSFXlist(int soundnum, int volume, Uint8 channels);

	// music running functions
	static int runmusic(std::string audioname, int volume, int loopamount, int fadeintime);
	static int runmusiclist(int audio, int volume, int loopamount, int fadeintime);

	// extra music optimisation functions
	static int endmusic(int fadeouttime); // measured in milliseconds
	static int volmusic(int volume); // max = 128

	// file searching sounds
	static void runsearchedaudiofile(int fileNumber, int volume, Uint8 channels);
	static int runfoundaudio(WCHAR* bufferSoundFile, int volume, Uint8 channels);

	// file searching music
	static void runsearchedmusicfile(int fileNumber, int volume, int loopamount, int fadeintime);
	static int runfoundmusic(WCHAR* bufferMusicFile, int volume, int loopamount, int fadeintime);
};