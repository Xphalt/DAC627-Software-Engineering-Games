#include "input_wrapper.h"
#include "gameobject.h"

input_wrapper::input_wrapper()
{
}

input_wrapper::~input_wrapper()
{
}

void input_wrapper::update()
{
}

void input_wrapper::execute_actions(gameobject& _gameobject)
{
	switch (m_actions)
	{
	case actions::UP:
		_gameobject.add_translation(0, 1);
		break;

	case actions::DOWN:
		_gameobject.add_translation(0, -1);
		break;

	case actions::LEFT:
		_gameobject.add_translation(-1, 0);
		break;

	case actions::RIGHT:
		_gameobject.add_translation(1, 0);
		break;

	case actions::ATTACK:
		break;

	case actions::PAUSE:
		break;
	}
}