#pragma once
#include "SDL.h"

static enum KEY_LIST //Global access. Convinient but might be removed.
{
	KEY_ESC,
	KEY_UP,
	KEY_LEFT,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_SPACE,
	KEY_LSHIFT,
	KEY_ENTER,
	KEY_P,
	SIZEOF_KEY_LIST
};
class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	void Update(SDL_Event eventKey);
	static bool KeyPressed(KEY_LIST key);
	static bool KeyHeld(KEY_LIST key);
	static void SetKeyHold();

private:
	static bool keysPressed[SIZEOF_KEY_LIST];
	static bool keysHeld[SIZEOF_KEY_LIST];
};


