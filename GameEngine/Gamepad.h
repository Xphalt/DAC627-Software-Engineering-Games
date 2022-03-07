#pragma once
#include <stdint.h>
#include <SDL.h>
#include <SDL_gamecontroller.h>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>

class gamepad
{
public:

	gamepad(SDL_Joystick* joy, SDL_GameController* newPad);
	~gamepad();

	SDL_Joystick* GetID() { return m_ID; }
	void PressButton(uint8_t button);
	void ReleaseButton(uint8_t button);
	void AxisChange(uint8_t axis);
	void RebindKey(uint8_t button, uint8_t newButton);
	void Event(SDL_Event event);
	void Update();
	int ProcessAxisInput(float input);
	bool IsButtonPressed(SDL_GameControllerButton button);
	bool IsButtonHeld(SDL_GameControllerButton button);
	float GetControllerAxis(SDL_GameControllerAxis axis);
	bool IsControllerInitialised();
	void Close();

private:

	SDL_Joystick* m_ID;
	SDL_GameController* pad;


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


	struct GamePadControls
	{
		bool buttons[SDL_CONTROLLER_BUTTON_MAX];
		int axis[SDL_CONTROLLER_AXIS_MAX];
	};

	GamePadControls m_controllerInputs;
	GamePadControls m_lastControllerInputs;
};