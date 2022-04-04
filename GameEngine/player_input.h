#pragma once

class gameobject;
class input_wrapper;
class keyboard_input;

class player_input
{
public:
	player_input();
	~player_input();

	void bind_actions(gameobject& _gameobject);

private:
	input_wrapper* m_input{ nullptr };
	keyboard_input* m_keyboard{ nullptr };
};