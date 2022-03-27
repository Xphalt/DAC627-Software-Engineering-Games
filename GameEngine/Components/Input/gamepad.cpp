#include "gamepad.h"

gamepad::gamepad(SDL_Joystick* joy, SDL_GameController* newPad)
{
	pad = newPad;
	m_ID = joy;
}

gamepad::~gamepad()
{

}

void gamepad::PressButton(uint8_t button)
{
	m_buttonsPressed[buttonBinds.find(button)->second] = true;
}

void gamepad::ReleaseButton(uint8_t button)
{
	m_buttonsPressed[buttonBinds.find(button)->second] = false;
}

void gamepad::AxisChange(uint8_t axis)
{
	if (axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT)
	{
		//if trigger is released, Then
		//ReleaseButton(axis);

		//else
		//PressButton(axis);
	}

	else if (axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT)
	{
		//if trigger is released, Then
		//ReleaseButton(axis);

		//else
		//PressButton(axis);
	}
}


void gamepad::RebindKey(uint8_t currentButton, uint8_t newButton)
{
	auto it = buttonBinds.find(currentButton); //Reminder find out the class later

	int action = it->second;

	buttonBinds.erase(it);
	buttonBinds.insert({ newButton, action });
}

void gamepad::Close()
{
	SDL_GameControllerClose(pad);
}

void gamepad::Update()
{
	for (int a = 0; a < SDL_CONTROLLER_AXIS_MAX; a++)
		m_lastControllerInputs.axis[a] = m_controllerInputs.axis[a];

	for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX; b++)
		m_lastControllerInputs.buttons[b] = m_controllerInputs.buttons[b];
}

void gamepad::Event(SDL_Event m_event)
{
	switch (m_event.type)
	{
	case SDL_CONTROLLERBUTTONDOWN:
			m_controllerInputs.buttons[m_event.cbutton.button] = true;
		break;

	case SDL_CONTROLLERBUTTONUP:
			m_controllerInputs.buttons[m_event.cbutton.button] = false;
		break;

	case SDL_CONTROLLERAXISMOTION:
			m_controllerInputs.axis[m_event.caxis.axis] = ProcessAxisInput(m_event.jaxis.value);
		break;
	}
}

int gamepad::ProcessAxisInput(float input)
{
	// Right or Down
	if (input > m_stickDeadZone)
		return 1;
	// Left or Up
	else if (input < -m_stickDeadZone)
		return -1;

	return 0;
}


bool gamepad::IsButtonPressed(SDL_GameControllerButton button)
{
	return m_controllerInputs.buttons[button] && !m_lastControllerInputs.buttons[button];
}

bool gamepad::IsButtonHeld(SDL_GameControllerButton button)
{
	return m_controllerInputs.buttons[button] && m_lastControllerInputs.buttons[button];
}

float gamepad::GetControllerAxis(SDL_GameControllerAxis axis)
{
	return m_controllerInputs.axis[axis];
}
