#include "InputMaster.h"
#include "Gamepad.h"

InputMaster::InputMaster()
{
	SDL_SetRelativeMouseMode(SDL_TRUE);
	InitialiseController();
}

InputMaster::~InputMaster()
{
	DestroyInput();
}

void InputMaster::InitialiseController()
{
	if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) == 0)
		SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);

	m_numGamepads = 0;

	SDL_GameControllerEventState(SDL_ENABLE);
}

void InputMaster::Update()
{
	for (int i = 0; i < m_numGamepads; i++)
	{
		for (int a = 0; a < SDL_CONTROLLER_AXIS_MAX; a++)
			m_lastControllerInputs[i].axis[a] = m_controllerInputs[i].axis[a];

		for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX; b++)
			m_lastControllerInputs[i].buttons[b] = m_controllerInputs[i].buttons[b];
	}

	if (/*Gamepad*/ true)
	{
		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
			case SDL_CONTROLLERDEVICEADDED:
				// TODO: Maybe limit how many controllers the game register
				if (SDL_IsGameController(m_event.cdevice.which))
					AddController(m_event.cdevice.which);

				break;

			case SDL_CONTROLLERDEVICEREMOVED:
				RemoveController(m_event.cdevice.which);
				break;

			case SDL_CONTROLLERBUTTONDOWN:
				// Cycle through the controllers
				for (int i = 0; i < m_numGamepads; i++)
				{
					// Looking for the button that was pressed
					if (m_event.cbutton.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(m_pConnectedControllers[i])))
						m_controllerInputs[i].buttons[m_event.cbutton.button] = true;
				}
				break;

			case SDL_CONTROLLERBUTTONUP:
				for (int i = 0; i < m_numGamepads; i++)
				{
					if (m_event.cbutton.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(m_pConnectedControllers[i])))
						m_controllerInputs[i].buttons[m_event.cbutton.button] = false;
				}
				break;

			case SDL_CONTROLLERAXISMOTION:
				for (int i = 0; i < m_numGamepads; i++)
				{
					if (m_event.cbutton.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(m_pConnectedControllers[i])))
						m_controllerInputs[i].axis[m_event.caxis.axis] = ProcessAxisInput(m_event.jaxis.value);
				}
				break;
			}
		}
	}

	while (SDL_PollEvent(&m_event))
	{

		SDL_Keycode keyPressed = m_event.key.keysym.sym;
		switch (m_event.type)
		{
		case SDL_KEYDOWN:
			if (keyPressed == SDLK_w) { m_keysPressed[UP] = true; }
			if (keyPressed == SDLK_s) { m_keysPressed[DOWN] = true; }
			if (keyPressed == SDLK_a) { m_keysPressed[LEFT] = true; }
			if (keyPressed == SDLK_d) { m_keysPressed[RIGHT] = true; }
			break;

		case SDL_KEYUP:
			if (keyPressed == SDLK_w) { m_keysPressed[UP] = false; }
			if (keyPressed == SDLK_s) { m_keysPressed[DOWN] = false; }
			if (keyPressed == SDLK_a) { m_keysPressed[LEFT] = false; }
			if (keyPressed == SDLK_d) { m_keysPressed[RIGHT] = false; }
			break;

		case SDL_MOUSEBUTTONDOWN:
			if (m_event.button.button == SDL_BUTTON_LEFT) { m_keysPressed[MELEEATTACK] = true; }
			else if (m_event.button.button == SDL_BUTTON_RIGHT) { m_keysPressed[RANGEATTACK] = true; }
			break;
		case SDL_MOUSEBUTTONUP:
			if (m_event.button.button == SDL_BUTTON_LEFT) { m_keysPressed[MELEEATTACK] = false; }
			else if (m_event.button.button == SDL_BUTTON_RIGHT) { m_keysPressed[RANGEATTACK] = false; }
			break;
		case SDL_MOUSEMOTION:
			m_event.motion.xrel;
			m_event.motion.yrel;
			break;
		}

	}
}

void InputMaster::DestroyInput()
{
	for (int i = 0; i < m_pConnectedControllers.size(); i++)
	{
		SDL_GameControllerClose(m_pConnectedControllers[i]);
		--m_numGamepads;
	}

	UpdateInputVectors();
}

bool InputMaster::IsButtonPressed(Controllers controllerID, SDL_GameControllerButton button)
{
	if (controllerID < 0 || controllerID >= m_numGamepads) return false;

	return m_controllerInputs[controllerID].buttons[button] && !m_lastControllerInputs[controllerID].buttons[button];
}

bool InputMaster::IsButtonHeld(Controllers controllerID, SDL_GameControllerButton button)
{
	if (controllerID < 0 || controllerID > m_numGamepads) return false;

	return m_controllerInputs[controllerID].buttons[button] && m_lastControllerInputs[controllerID].buttons[button];
}

float InputMaster::GetControllerAxis(Controllers controllerID, SDL_GameControllerAxis axis)
{
	if (controllerID < 0 || controllerID > m_numGamepads) return 0.0;

	return m_controllerInputs[controllerID].axis[axis];
}

bool InputMaster::IsControllerInitialised()
{
	return m_isControllerInitialised;
}

void InputMaster::UpdateInputVectors()
{
	m_controllerInputs.resize(m_numGamepads);
	m_lastControllerInputs.resize(m_numGamepads);
}

void InputMaster::AddController(int deviceID) //This needs some identifier
{
	Gamepad* Test = new Gamepad(deviceID);

#if _DEBUG
	std::cout << "Device has been connected" << std::endl;

	std::cout << SDL_GameControllerName(Test->pad) << std::endl;
#endif // _DEBUG

	if (SDL_GameControllerGetAttached(Test->pad)) //true if connected and functioning. False if not.
	{
		m_pConnectedControllers.push_back(Test->pad);
		m_isControllerInitialised = true;

		++m_numGamepads;

		UpdateInputVectors();
	}
}

void InputMaster::RemoveController(int deviceID)
{
	SDL_Joystick* joystick = SDL_JoystickFromInstanceID(deviceID);

	for (size_t i = 0; i < m_pConnectedControllers.size(); i++)
	{
		SDL_Joystick* tempJoystick = SDL_GameControllerGetJoystick(m_pConnectedControllers[i]);

		if (tempJoystick == joystick)
		{
			SDL_GameControllerClose(m_pConnectedControllers[i]);

			m_pConnectedControllers.erase(m_pConnectedControllers.begin() + i);

			--m_numGamepads;

#if _DEBUG
			std::cout << "Device has been removed" << std::endl;
#endif // _DEBUG

			UpdateInputVectors();

			if (m_numGamepads == 0)
				m_isControllerInitialised = false;
		}
	}
}

int InputMaster::ProcessAxisInput(float input)
{
	// Right or Down
	if (input > m_mouseDeadZone)
		return 1;
	// Left or Up
	else if (input < -m_mouseDeadZone)
		return -1;

	return 0;
}