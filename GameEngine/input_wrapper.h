#pragma once

class gameobject;

enum actions
{
	LEFT, RIGHT, UP, DOWN, ATTACK, PAUSE, SIZE_OF_ACTION_KEYS
};

class input_wrapper
{
public:
	input_wrapper();
	~input_wrapper();

	void update();
	void execute_actions(gameobject& _gameobject);
	void set_actions(actions _action) { m_actions = _action; }
private:
	actions m_actions;
};