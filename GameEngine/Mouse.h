#pragma once
#include <vector>
#include "SDL.h"

enum BUTTON_LIST
{
	BUTTON_LEFT,
	BUTTON_RIGHT,
	SIZEOF_BUTTON_LIST
};

class Mouse
{
public:
	Mouse();
	~Mouse();
	void Update(SDL_Event mouseEvent);
	static bool ButtonPressed(BUTTON_LIST button);
	static bool ButtonHeld(BUTTON_LIST button);
	static void SetButtonHold();
	SDL_Point GetMousePos();
	void SetMousePos(int x, int y);
	void SetMousePos(SDL_Point newPos);

private:
	SDL_Point* m_pMousePos;
	static bool buttonPressed[SIZEOF_BUTTON_LIST];
	static bool buttonHeld[SIZEOF_BUTTON_LIST];
};

