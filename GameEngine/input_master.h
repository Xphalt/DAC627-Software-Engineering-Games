#pragma once
#include <SDL.h>
#include <SDL_joystick.h>
#include <SDL_gamecontroller.h>
#include <iostream>
#include <vector>
#include "gamepad.h"
#include "Keyboard.h"
#include "Mouse.h"

enum ActionKeys
{
	PAUSE, UP, DOWN, LEFT, RIGHT, MELEEATTACK, RANGEATTACK, QUIT, SIZE_OF_ACTION_KEYS
};

enum Controllers
{
	PLAYER1 = 0, PLAYER2, totalControllers
};

class input_master
{
public:
	input_master();
	~input_master();

	void InitialiseController();
	void Update();
	void DestroyInput();

	bool IsButtonPressed(Controllers controllerID, SDL_GameControllerButton button);
	bool IsButtonHeld(Controllers controllerID, SDL_GameControllerButton button);
	float GetControllerAxis(Controllers controllerID, SDL_GameControllerAxis axis);

	bool key_pressed(ActionKeys key);

	bool IsControllerInitialised();
	int GetNumberOfConnectedControllers() { return m_numGamepads; }

protected:
	SDL_Event m_event;

	//std::vector<SDL_GameController*> m_pConnectedControllers;
	std::vector<gamepad*> m_pConnectedControllers;
	int m_numGamepads = 0;

	void AddController(int deviceID);
	void RemoveController(int deviceID);

	//bool m_isControllerInitialised = false;

	Keyboard* m_pKeyboard;
	bool m_keysPressed[SIZE_OF_ACTION_KEYS];

	Mouse* m_pMouse;
};