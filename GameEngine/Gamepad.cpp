#include "Gamepad.h"

Gamepad::Gamepad(int ID)
{
	pad = SDL_GameControllerOpen(ID);
}

Gamepad::~Gamepad()
{
}

void Gamepad::PressButton(uint8_t button)
{
	m_buttonsPressed[buttonBinds.find(button)->second] = true;
}

void Gamepad::ReleaseButton(uint8_t button)
{
	m_buttonsPressed[buttonBinds.find(button)->second] = false;
}

void Gamepad::AxisChange(uint8_t axis)
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


void Gamepad::RebindKey(uint8_t currentButton, uint8_t newButton)
{
	auto it = buttonBinds.find(currentButton); //Reminder find out the class later

	int action = it->second;

	buttonBinds.erase(it);
	buttonBinds.insert({ newButton, action });
}