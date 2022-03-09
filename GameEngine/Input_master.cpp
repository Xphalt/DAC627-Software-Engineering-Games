#include "input_master.h"
#include "gamepad.h"

input_master::input_master()
{
	SDL_SetRelativeMouseMode(SDL_TRUE);
	InitialiseController();
}

input_master::~input_master()
{
	DestroyInput();
}

void input_master::InitialiseController()
{
	if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) == 0)
		SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);

	m_numGamepads = 0;

	SDL_GameControllerEventState(SDL_ENABLE);
}

void input_master::Update()
{
	for (int i = 0; i < m_numGamepads; i++)
	{
		m_pConnectedControllers[i]->Update();
	}

<<<<<<< Updated upstream:GameEngine/Input_master.cpp
	if (/*gamepad*/ true)
=======
	if (m_pConnectedControllers.size() > 0)
>>>>>>> Stashed changes:GameEngine/InputMaster.cpp
	{
		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
				case SDL_KEYDOWN:
					m_pKeyboard->Update(m_event);
					break;

				case SDL_KEYUP:
					m_pKeyboard->Update(m_event);
					break;
				
				case SDL_MOUSEBUTTONDOWN:
					m_pMouse->Update(m_event);
					break;

				case SDL_MOUSEBUTTONUP:
					m_pMouse->Update(m_event);
					break;


				case SDL_CONTROLLERDEVICEADDED:
					// TODO: Maybe limit how many controllers the game register
					if (SDL_IsGameController(m_event.cdevice.which))
						AddController(m_event.cdevice.which);

					break;

				case SDL_CONTROLLERDEVICEREMOVED:
					RemoveController(m_event.cdevice.which);
					break;

				default:
					SDL_Joystick* tJoy = SDL_JoystickFromInstanceID(m_event.cdevice.which);

					for (int i = 0; i < m_numGamepads; i++)
					{
						if (tJoy == m_pConnectedControllers[i]->GetID())
							m_pConnectedControllers[i]->Event(m_event);
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

void input_master::DestroyInput()
{
	for (int i = 0; i < m_pConnectedControllers.size(); i++)
	{
		m_pConnectedControllers[i]->Close();
		--m_numGamepads;
	}
}

//bool input_master::IsControllerInitialised()
//{
//	return m_isControllerInitialised;
//}

void input_master::AddController(int deviceID) //This needs some identifier
{
	SDL_GameController* pad = SDL_GameControllerOpen(deviceID);

#if _DEBUG
	std::cout << "Device has been connected" << std::endl;

	std::cout << SDL_GameControllerName(pad) << std::endl;
#endif // _DEBUG

	if (SDL_GameControllerGetAttached(pad)) //true if connected and functioning. False if not.
	{
		SDL_Joystick* tempjoy = SDL_GameControllerGetJoystick(pad);

		/*gamepad testboy = new gamepad(tempjoy);*/

		m_pConnectedControllers.push_back(new gamepad(tempjoy, pad));
		//m_isControllerInitialised = true;

		++m_numGamepads;
	}
}

void input_master::RemoveController(int deviceID)
{
	SDL_Joystick* joystick = SDL_JoystickFromInstanceID(deviceID);

	for (int i = 0; i < m_pConnectedControllers.size(); i++)
	{

		if (joystick == m_pConnectedControllers[i]->GetID())
		{
			m_pConnectedControllers[i]->Close();

			--m_numGamepads;

#if _DEBUG
			std::cout << "Device has been removed" << std::endl;
#endif // _DEBUG

			//if (m_numGamepads == 0)
			//	m_isControllerInitialised = false;
		}
	}
}
