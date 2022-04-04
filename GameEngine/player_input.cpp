#include "player_input.h"
#include "gameobject.h"
#include "input_wrapper.h"
#include "keyboard_input.h"

player_input::player_input()
{

}

player_input::~player_input()
{
}

void player_input::Execute()
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