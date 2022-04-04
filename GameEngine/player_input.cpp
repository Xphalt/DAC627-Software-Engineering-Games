#include "player_input.h"
#include "gameobject.h"
#include "input_wrapper.h"
#include "keyboard_input.h"
#include "gamepad_input.h"

player_input::player_input(keyboard_input* _keyboard, gamepad_input* _gamepad)
	: m_keyboard{_keyboard}, m_gamepad{_gamepad}
{

}

player_input::~player_input()
{
}

void player_input::Execute()
{
	if (m_gamepad->GetControllerInitialised())
	{
		switch (m_gamepad->get_buttons())
		{
		case Buttons::UP:
			m_input->set_actions(actions::UP);
			break;

		case Buttons::LEFT:
			m_input->set_actions(actions::LEFT);
			break;

		case Buttons::RIGHT:
			m_input->set_actions(actions::RIGHT);
			break;

		case Buttons::DOWN:
			m_input->set_actions(actions::DOWN);
			break;
		}
	}

	else
	{
		switch (m_keyboard->get_key())
		{
		case Keys::KEY_W:
			m_input->set_actions(actions::UP);
			break;

		case Keys::KEY_A:
			m_input->set_actions(actions::LEFT);
			break;

		case Keys::KEY_S:
			m_input->set_actions(actions::RIGHT);
			break;

		case Keys::KEY_D:
			m_input->set_actions(actions::DOWN);
			break;
		}
	}
}