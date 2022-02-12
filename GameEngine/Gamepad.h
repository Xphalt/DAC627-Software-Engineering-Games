#pragma once
#include <stdint.h>
#include <SDL.h>
#include <SDL_gamecontroller.h>
#include <map>
#include <algorithm>
#include <iostream>

class Gamepad
{
public:

	Gamepad(int ID);
	~Gamepad();

	int GetID() { return m_ID; }
	void PressButton(uint8_t button);
	void ReleaseButton(uint8_t button);
	void AxisChange(uint8_t axis);
	void RebindKey(uint8_t button, uint8_t newButton);

	SDL_GameController* pad;

private:
	int m_ID;

	int m_stickDeadZone = 25000;
	int m_triggerDeadZone = 40000;

	enum ActionButtons
	{
		PAUSE, ACCEPT, DECLINE, MELEEATTACK, RANGEATTACK, SIZE_OF_ACTION_BUTTONS,
	};

	bool m_buttonsPressed[SIZE_OF_ACTION_BUTTONS];

	std::map<int, int> buttonBinds
	{
		{SDL_CONTROLLER_BUTTON_START, PAUSE}, //6
		{SDL_CONTROLLER_BUTTON_A, ACCEPT}, //0
		{SDL_CONTROLLER_BUTTON_B, DECLINE}, //1
		{SDL_CONTROLLER_AXIS_TRIGGERLEFT, MELEEATTACK}, //4
		{SDL_CONTROLLER_AXIS_TRIGGERRIGHT, RANGEATTACK}, //5
	};
};