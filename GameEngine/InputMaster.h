#pragma once
#include <SDL.h>
#include <SDL_gamecontroller.h>
#include <iostream>
#include <vector>
#include "Gamepad.cpp"

struct GamePadControls
{
	bool buttons[SDL_CONTROLLER_BUTTON_MAX];
	int axis[SDL_CONTROLLER_AXIS_MAX];
};

enum ActionKeys
{
	PAUSE, UP, DOWN, LEFT, RIGHT, MELEEATTACK, RANGEATTACK, SIZE_OF_ACTION_KEYS
};

enum Controllers
{
	PLAYER1 = 0, PLAYER2, totalControllers
};

int m_mouseDeadZone = 25000;

class InputMaster
{
public:
	InputMaster();
	~InputMaster();

	void InitialiseController();
	void Update();
	void DestroyInput();

	bool IsButtonPressed(Controllers controllerID, SDL_GameControllerButton button);
	bool IsButtonHeld(Controllers controllerID, SDL_GameControllerButton button);
	float GetControllerAxis(Controllers controllerID, SDL_GameControllerAxis axis);

	bool IsControllerInitialised();
	int GetNumberOfConnectedControllers() { return m_numGamepads; }

protected:
	SDL_Event m_event;

	std::vector<SDL_GameController*> m_pConnectedControllers;
	std::vector<GamePadControls> m_controllerInputs;
	std::vector<GamePadControls> m_lastControllerInputs;
	int m_numGamepads = 0;

	void UpdateInputVectors();

	void AddController(int deviceID);
	void RemoveController(int deviceID);

	int ProcessAxisInput(float input);

	bool m_isControllerInitialised = false;

	bool m_keysPressed[SIZE_OF_ACTION_KEYS];
};